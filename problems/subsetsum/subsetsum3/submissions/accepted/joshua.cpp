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


    int n, t;
    cin >> n >> t;

    vi nums(n);
    rep(i, n) cin >> nums[i];
    
    int s = 0;
    int i = 0;
    while (i < n && s + nums[i] <= t) s += nums[i++];
    rep(j, i) nums[j] = -nums[j];
    mt19937 rng(10);
    shuffle(all(nums), rng);

    const constexpr int bs_size = int(1e5);
    bitset<bs_size> bset;
    bset[bs_size / 2] = 1;

    repe(num, nums)
    {
        if (num < 0) bset |= bset >> (-num);
        else bset |= bset << num;
    }
    
    int largest = 0;
    repp(i, bs_size/2, bs_size)
    {
        if (i - bs_size / 2 + s > t) break;
        if (bset[i]) largest = i - bs_size / 2;
    }
    cout << s + largest;

    return 0;
}
