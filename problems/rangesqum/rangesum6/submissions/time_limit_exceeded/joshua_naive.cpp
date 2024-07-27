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
#define ceildiv(x,y) (((x) + (y) - 1) / (y))

inline void fast() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

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
        int t, l, r;
        cin >> t >> l >> r;

        if (t==1)
        {
            int h;
            cin >> h;
            repp(i, l, r + 1) nums[i] = min(nums[i], h);
        }
        else if (t==2)
        {
            int x;
            cin >> x;
            repp(i, l, r + 1) nums[i] += x;
        }
        else if (t==3)
        {
            int s = 0;
            repp(i, l, r + 1) s += nums[i];
            cout << s << "\n";
        }
    }

    return 0;
}
