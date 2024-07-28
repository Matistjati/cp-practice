// Sponsored by ChatGPT
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

int ans(const vector<bool>& s)
{
    int maxLen = 1, currentLen = 1;
    repp(i, 1, sz(s))
    {
        if (s[i] == s[i - 1])
        {
            currentLen++;
        }
        else
        {
            maxLen = max(maxLen, currentLen);
            currentLen = 1;
        }
    }
    return max(maxLen, currentLen);
}

void xor_range(vector<bool>& s, int l, int r)
{
    for (int i = l; i <= r; ++i)
    {
        s[i] = s[i] ^ 1;
    }
}

void sort_range(vector<bool>& s, int l, int r)
{
    int countOnes = 0;
    repp(i, l, r + 1) countOnes += s[i];

    repp(i, l, r + 1)
    {
        s[i] = (i < l + countOnes) ? 1 : 0;
    }
}


signed main()
{
    fast();

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<bool> bits(n);
    rep(i, n) if (s[i] == '1') bits[i] = 1;

    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1) xor_range(bits, l, r);
        if (t == 2) sort_range(bits, l, r);

        cout << ans(bits) << endl;
    }

    return 0;
}
