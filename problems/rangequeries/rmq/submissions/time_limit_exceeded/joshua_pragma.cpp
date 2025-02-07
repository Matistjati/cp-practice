#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;


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
	rep(i, n) cin >> nums[i];

	while (q--)
	{
		int l, r;
		cin >> l >> r;
		int ans = int(3e5);
		repp(i, l, r + 1) ans = min(ans, nums[i]);
		cout << ans << "\n";
	}

	return 0;
}
