#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using p2 = pair<ll, ll>;
const ll inf = 1e18;

#define rep(i,n) for (ll i = 0; i < (n); i++)
#define repp(i,a,n) for (ll i = (a); i < (n); i++)
#define repe(i, arr) for (auto& i : arr)
#define all(x) begin(x),end(x)
#define sz(x) ((ll)(x).size())

struct Tree
{
    const int unit = 0;
    int n;
    vector<ll> tree;
    Tree(int n) : n(n), tree(n * 4, unit) {}

    ll merge(ll a, ll b)
    {
        return a+b;
    }

    void update(int x, int l, int r, int i, int v)
    {
        if (l == r) tree[x] = v;
        else
        {
            int mid = (l + r) / 2;
            if (i <= mid) update(x * 2, l, mid, i, v);
            else update(x * 2 + 1, mid + 1, r, i, v);
            tree[x] = merge(tree[x * 2], tree[x * 2 + 1]);
        }
    }

    void update(int i, int v) { update(1, 0, n - 1, i, v); }

    ll query(int x, int l, int r, int ql, int qr)
    {
        if (l > qr || r < ql) return unit;
        if (l >= ql && r <= qr) return tree[x];

        int mid = (l + r) / 2;
        return merge(query(x * 2, l, mid, ql, qr), query(x * 2 + 1, mid + 1, r, ql, qr));
    }

    ll query(int ql, int qr) { return query(1, 0, n - 1, ql, qr); }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n,q;
    cin >> n >> q;

    vi nums(n);
    rep(i,n) cin >> nums[i];

    Tree tree(n);
    rep(i, n) tree.update(i, nums[i]);

    rep(i, q)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            cout << tree.query(l, r) << endl;
        }
        else{
            tree.update(l, r);
        }
    }

    return 0;
}
