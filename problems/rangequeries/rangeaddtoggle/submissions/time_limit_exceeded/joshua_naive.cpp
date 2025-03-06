#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
const int inf = int(1e18);

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> p2;

#define rep(i, high) for (int i = 0; i < (high); i++)
#define repp(i, low, high) for (int i = (low); i < (high); i++)
#define repe(i, container) for (auto& i : container)
#define sz(container) ((int)container.size())
#define all(x) begin(x),end(x)

inline void fast() { cin.tie(0)->sync_with_stdio(0); }

#if _LOCAL
#define assert(x) if (!(x)) __debugbreak()
#endif

signed main()
{
	fast();

	int n, q;
	cin >> n >> q;
	vi nums(n);
	vi active(n);

	while (q--)
	{
		int t;
		cin >> t;
		if (t==1)
		{
			int i;
			cin >> i;
			cout << nums[i] << "\n";
		}
		else if (t==2)
		{
			int l,r, v;
			cin >> l >> r >> v;
			repp(i,l,r+1) if (active[i]) nums[i] += v;
		}
		else
		{
			int i;
			cin >> i;
			active[i] ^= 1;
		}
	}
	rep(i,n) cout << nums[i] << " ";

	return 0;
}
