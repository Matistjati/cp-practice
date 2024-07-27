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

mt19937 rng;
uniform_int_distribution<int> dist(1, int(1e9));
struct node
{
    int cnt, prio;
    int value, sum;
    int lazy;
    node* l, * r;
    node(int value) : cnt(1), prio(dist(rng)), value(value), sum(value), lazy(0), l(nullptr), r(nullptr) {}
};

typedef node* pnode;
int get_cnt(pnode x) { return x ? x->cnt : 0; }
int get_sum(pnode x) { return x ? x->sum : 0; }


void push_add(pnode x, int v)
{
    if (!x) return;
    x->sum += v * x->cnt;
    x->lazy += v;
    x->value += v;
}

void push(pnode x)
{
    if (!x) return;
    if (x->lazy)
    {
        push_add(x->l, x->lazy);
        push_add(x->r, x->lazy);
        x->lazy = 0;
    }
}


void pull(pnode x)
{
    if (!x) return;
    x->cnt = get_cnt(x->l) + get_cnt(x->r) + 1;
    x->sum = get_sum(x->l) + get_sum(x->r) + x->value;
}

void split(pnode x, pnode& l, pnode& r, int i, int add = 0)
{
    if (!x)
        return void(l = r = nullptr);
    push(x);
    int real_i = get_cnt(x->l) + add;
    if (i <= real_i)
        split(x->l, l, x->l, i, add), r = x;
    else
        split(x->r, x->r, r, i, add + 1 + get_cnt(x->l)), l = x;
    pull(x);
}

void merge(pnode& x, pnode l, pnode r)
{
    if (l) push(l);
    if (r) push(r);
    if (!l || !r)
        x = l ? l : r;
    else if (l->prio < r->prio)
        merge(r->l, l, r->l), x = r;
    else
        merge(l->r, l->r, r), x = l;
    pull(x);
}

int rsq(pnode& x, int ql, int qr)
{
    pnode l, mid, r;
    split(x, l, r, qr + 1);
    split(l, l, mid, ql);
    int ret = mid->sum;
    merge(l, l, mid);
    merge(x, l, r);
    return ret;
}

void add(pnode& x, int ql, int qr, int v)
{
    pnode l, mid, r;
    split(x, l, r, qr + 1);
    split(l, l, mid, ql);

    push_add(mid, v);

    merge(l, l, mid);
    merge(x, l, r);
}

signed main()
{
    fast();


    int n, q;
    cin >> n >> q;
    pnode root = nullptr;
    rep(i, n)
    {
        int v;
        cin >> v;
        pnode new_node = new node(v);
        merge(root, root, new_node);
    }

    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1)
        {
            assert(0);
        }
        else if (t==2)
        {
            int x;
            cin >> x;
            add(root, l, r, x);
        }
        else if (t == 3)
        {
            cout << rsq(root, l, r) << "\n";
        }
    }

    flush(cout);
    _Exit(0);
    return 0;
}
