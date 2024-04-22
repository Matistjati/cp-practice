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

int cnt(int u, int p, int d, vvi& edges)
{
	if (d == 0) return 1;
	int ret = 1;
	repe(e, edges[u]) if (e != p) ret += cnt(e, u, d-1, edges);
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

	while (q--)
	{
		int u, d;
		cin >> u >> d;
		cout << cnt(u, u, d, edges) << "\n";

	}

	return 0;
}
