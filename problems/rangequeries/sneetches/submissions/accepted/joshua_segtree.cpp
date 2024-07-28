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

struct Tree
{
    int n;
    vi lp[2], rp[2], mp[2]; // 0=0, 1=1
    vi zerocnt;
    vi push_set, lazy_xor;
    vi cnt;

    Tree(int n) : n(n), zerocnt(n * 4), push_set(n * 4, -1), lazy_xor(n * 4), cnt(n * 4)
    {
        rep(f, 2)
        {
            lp[f] = vi(n * 4);
            rp[f] = vi(n * 4);
            mp[f] = vi(n * 4);
        }
        build(1, 0, n - 1);
    }

    void pull_interval(int x, bool f)
    {
        lp[f][x] = lp[f][x * 2];
        rp[f][x] = rp[f][x * 2 + 1];
        mp[f][x] = max(mp[f][x * 2], mp[f][x * 2 + 1]);
        mp[f][x] = max(mp[f][x], rp[f][x * 2] + lp[f][x * 2 + 1]);
        if (lp[f][x * 2] == cnt[x * 2]) lp[f][x] = lp[f][x * 2] + lp[f][x * 2 + 1];
        if (rp[f][x * 2 + 1] == cnt[x * 2 + 1]) rp[f][x] = rp[f][x * 2] + rp[f][x * 2 + 1];
    }

    void pull(int x)
    {
        pull_interval(x, 0);
        pull_interval(x, 1);
        zerocnt[x] = zerocnt[x * 2] + zerocnt[x * 2 + 1];
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            cnt[x] = 1;
            lp[0][x] = 1;
            rp[0][x] = 1;
            mp[0][x] = 1;
            // lp[1] is 0
            zerocnt[x] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(x * 2, l, mid);
        build(x * 2 + 1, mid + 1, r);

        cnt[x] = cnt[x * 2] + cnt[x * 2 + 1];
        pull(x);
    }

    void apply_set(int x, int v)
    {
        lp[v][x] = rp[v][x] = mp[v][x] = cnt[x];
        lp[!v][x] = rp[!v][x] = mp[!v][x] = 0;
        lazy_xor[x] = 0;
        if (v) zerocnt[x] = 0;
        else zerocnt[x] = cnt[x];
        push_set[x] = v;
    }

    void apply_xor(int x)
    {
        if (push_set[x] != -1)
        {
            push_set[x] = !push_set[x];
            apply_set(x, push_set[x]);
            return;
        }
        swap(lp[0][x], lp[1][x]);
        swap(rp[0][x], rp[1][x]);
        swap(mp[0][x], mp[1][x]);
        lazy_xor[x] ^= 1;
        zerocnt[x] = cnt[x] - zerocnt[x];
    }

    void push(int x)
    {
        if (push_set[x]!=-1)
        {
            apply_set(x * 2, push_set[x]);
            apply_set(x * 2 + 1, push_set[x]);
            push_set[x] = -1;
        }
        if (lazy_xor[x] == 0) return;
        apply_xor(x * 2);
        apply_xor(x * 2 + 1);
        lazy_xor[x] = 0;
    }

    void range_xor(int x, int l, int r, int ql, int qr)
    {
        if (r < ql || l > qr) return;
        if (l >= ql && r <= qr)
        {
            apply_xor(x);
            return;
        }
        push(x);

        int mid = (l + r) / 2;
        range_xor(x * 2, l, mid, ql, qr);
        range_xor(x * 2 + 1, mid + 1, r, ql, qr);
        pull(x);
    }
    
    int query_zeros(int x, int l, int r, int ql, int qr)
    {
        if (l > qr || r < ql) return 0;
        if (l >= ql && r <= qr) return zerocnt[x];
        push(x);
        int mid = (l + r) / 2;
        return query_zeros(x * 2, l, mid, ql, qr) + query_zeros(x * 2 + 1, mid + 1, r, ql, qr);
    }

    void range_set(int x, int l, int r, int ql, int qr, int v)
    {
        if (l > qr || r < ql) return;
        if (l >= ql && r <= qr)
        {
            apply_set(x, v);
            return;
        }
        push(x);

        int mid = (l + r) / 2;
        range_set(x * 2, l, mid, ql, qr, v);
        range_set(x * 2 + 1, mid + 1, r, ql, qr, v);

        pull(x);
    }

    void range_sort(int ql, int qr)
    {
        int num_zeros = query_zeros(1, 0, n - 1, ql, qr);
        range_set(1, 0, n - 1, ql, ql + num_zeros - 1, 0);
        range_set(1, 0, n - 1, ql + num_zeros, qr, 1);
    }
};

signed main()
{
    fast();

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    Tree tree(n);
    rep(i, n)
    {
        if (s[i] == '1') tree.range_xor(1, 0, n - 1, i, i);
    }

    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1)
        {
            tree.range_xor(1, 0, n - 1, l, r);
        }
        if (t==2)
        {
            tree.range_sort(l, r);
        }
        cout << max(tree.mp[0][1], tree.mp[1][1]) << "\n";
    }

    return 0;
}
