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
#define __builtin_clz 
#define assert(x) if (!(x)) __debugbreak()
#endif

typedef bitset<4000000 + 10> bset;

signed main()
{
    fast();

    int n, t;
    cin >> n >> t;

    vvi enabled(n);

    bset dp;
    dp[0] = 1;
    vi nums;
    rep(i, n)
    {
        int v;
        cin >> v;
        nums.push_back(v);
        bset diff = (dp << v) & ~dp;
        dp |= dp << v;
        for (int j = diff._Find_first(); j < sz(dp); j = diff._Find_next(j))
        {
            enabled[i].push_back(j);
        }
    }

    if (!dp[t])
    {
        cout << "NO\n";
        return 0;
    }
    
    vi ans;
    int i = n - 1;
    while (t)
    {
        if (find(all(enabled[i]), t)!=enabled[i].end())
        {
            ans.push_back(nums[i]);
            t -= nums[i];
        }
        i--;
    }
    cout << "YES\n";
    cout << sz(ans) << "\n";
    repe(u, ans) cout << u << " ";
    cout << "\n";
    
    return 0;
}
