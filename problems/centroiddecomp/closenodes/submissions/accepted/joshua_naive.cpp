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

int dist(int u, int p, vi& color, vvi& edges)
{
	if (color[u]) return 0;
	int ret = inf;
	repe(e, edges[u]) if (e != p) ret = min(ret, 1 + dist(e, u, color, edges));
	return ret;
}

signed main()
{
	fast();

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
	vi color(n);
	color[0] = 1;
	
	while (q--)
	{
		int t, u;
		cin >> t >> u;
		if (t)
		{
			cout << dist(u, u, color, edges) << "\n";
		}
		else
		{
			color[u] = 1;
		}
	}

	return 0;
}
