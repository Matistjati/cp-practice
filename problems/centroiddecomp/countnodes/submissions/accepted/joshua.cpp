#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
const int inf = int(1e18);

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> p2;

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define sz(container) ((int)container.size())
#define all(x) begin(x),end(x)
#define ceildiv(x,y) ((x + y - 1) / (y))

inline void fast() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

auto Start = chrono::high_resolution_clock::now();
void resettimer() { Start = chrono::high_resolution_clock::now(); }
int elapsedmillis() { return chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - Start).count(); }

#if _LOCAL
#define assert(x) if (!(x)) __debugbreak()
#endif

struct Centroid
{
	vi paredgeindex;
	vi deg;
	vi size;
	vi vis;
	vi par;
	vvi adj;
	Centroid(vvi& adj) : adj(adj), size(sz(adj)), vis(sz(adj)), par(sz(adj)), deg(sz(adj)), paredgeindex(sz(adj))
	{
		init_centroid(0, -1);
	}

	int calc_size(int u, int p)
	{
		if (vis[u]) return 0;

		size[u] = 1;
		repe(e, adj[u]) if (e != p)size[u] += calc_size(e, u);
		return size[u];
	}

	int find_centroid(int u, int p, int s)
	{
		repe(e, adj[u])
		{
			if (e == p) continue;
			if (!vis[e] && size[e] > s / 2) return find_centroid(e, u, s);
		}
		return u;
	}

	void init_centroid(int u, int p)
	{
		calc_size(u, u);

		int c = find_centroid(u, u, size[u]);
		par[c] = p;
		if (p != -1) paredgeindex[c] = deg[p]++;
		vis[c] = 1;

		repe(e, adj[c])
		{
			if (!vis[e]) init_centroid(e, c);
		}
	}
};

const int maxn = int(2e5);

int tin[maxn];
int tout[maxn];
int timer = 0;
int up[maxn][19];
int depth[maxn];

void dfs(int u, int p, vvi& adj)
{
	depth[u] = depth[p] + 1;
	tin[u] = timer++;
	up[u][0] = p;
	repp(d, 1, 19) up[u][d] = up[up[u][d - 1]][d - 1];

	repe(e, adj[u]) if (e != p) dfs(e, u, adj);

	tout[u] = timer++;
}

int isancestor(int a, int b)
{
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b)
{
	if (isancestor(a, b)) return a;
	if (isancestor(b, a)) return b;

	for (int d = 18; d >= 0; d--)
	{
		if (!isancestor(up[a][d], b))
		{
			a = up[a][d];
		}
	}
	return up[a][0];
}

int dist(int a, int b)
{
	return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}

int jump(int u, int h)
{
	for (int d = 18; d >= 0; d--)
		if (h & (1 << d)) u = up[u][d];
	return u;
}

signed main()
{
	fast();

	//ifstream in("C:\\users\\matis\\desktop\\comp_prog\\x64\\debug\\in.txt");
	//cin.rdbuf(in.rdbuf());

	int n, q;
	cin >> n >> q;
	vvi edges(n);

	rep(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	depth[0] = -1;
	dfs(0, 0, edges);

	Centroid centroid(edges);
	vi par = centroid.par;
	vi pareindex = centroid.paredgeindex;

	vvi pref(n);
	vector<vvi> edgepref(n);
	rep(i,n) edgepref[i] = vvi(sz(edges[i]));
	rep(i, n)
	{
		int u = i;
		while (u!=-1)
		{
			int d = dist(u, i);
			pref[u].push_back(d);
			u = par[u];
		}

		u = i;
		while (par[u]!=-1)
		{
			int d = dist(par[u], i);
			edgepref[par[u]][pareindex[u]].push_back(d);
			u = par[u];
		}
	}
	rep(i, n)
	{
		int prev = 0;
		sort(all(pref[i]));
		
		repe(e, edgepref[i])
		{
			sort(all(e));
		}
	}

	auto query = [&](int d, vi& pref)
	{
		auto it = upper_bound(all(pref), d);
		if (it == pref.begin()) return 0LL;
		return (int)(it-begin(pref));
	};

	int ans = 0;
	while (q--)
	{
		int s, d;
		cin >> s >> d;
		int cnt = 0;
		int u = s;
		while (u != -1)
		{
			cnt += query(d-dist(u,s), pref[u]);
			if (par[u] != -1) cnt -= query(d-dist(par[u],s), edgepref[par[u]][pareindex[u]]);
			u = par[u];
		}

		cout << cnt << "\n";
	}

	return 0;
}