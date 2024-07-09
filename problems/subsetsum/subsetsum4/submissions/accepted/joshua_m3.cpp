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


signed main()
{
    fast();

    int m, t;
    cin >> m >> t;

    vi count(m + 1);
    rep(i, m + 1) cin >> count[i];

    int tot = 0;
    rep(i, m+1) tot += i * count[i];
    if (tot<t)
    {
        cout << "NO\n";
        return 0;
    }

    vi neg_count(m + 1);
    rep(i, m + 1)
    {
        if (i * count[i] <= t)
        {
            t -= i * count[i];
            neg_count[i] = count[i];
        }
        else
        {
            assert(i);
            int can_take = t / i;
            t -= i * can_take;
            assert(t >= 0);
            neg_count[i] = can_take;
        }
    }

    int max_sz = m * m + 10;
    vi dp(max_sz * 2, inf);
    dp[max_sz] = 0;
    assert(max_sz + t < sz(dp));

    auto add_positive = [&](int v, int cnt)
    {
        rep(i, sz(dp))
        {
            if (i - v < 0) continue;
            dp[i] = min(dp[i], dp[i - v] + 1);
        }
        rep(i, sz(dp))
        {
            if (dp[i] <= cnt) dp[i] = 0;
            else dp[i] = inf;
        }
    };

    auto add_negative = [&](int v, int cnt)
    {
        for (int i = sz(dp) - 1; i >= 0; i--)
        {
            if (i + v >= sz(dp)) continue;
            dp[i] = min(dp[i], dp[i + v] + 1);
        }
        rep(i, sz(dp))
        {
            if (dp[i] <= cnt) dp[i] = 0;
            else dp[i] = inf;
        }
    };

    rep(i, m + 1)
    {
        int pcount = count[i] - neg_count[i];
        if (pcount > 0) add_positive(i, pcount);
        int negcount = neg_count[i];
        if (negcount > 0) add_negative(i, negcount);
    }

    cout << (dp[max_sz + t] == 0 ? "YES" : "NO") << "\n";

    return 0;
}
