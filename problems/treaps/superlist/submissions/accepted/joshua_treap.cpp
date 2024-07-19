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
uniform_int_distribution<int> dist(0, int(1e9));
struct node
{
    int prio, key, cnt;
    node *l, *r;
    node(int key) : prio(dist(rng)), key(key), cnt(1), l(nullptr), r(nullptr) {}
};

typedef node* pnode;
int get_cnt(pnode x)
{
    return x ? x->cnt : 0;
}

void upd_cnt(pnode x)
{
    if (x) x->cnt = get_cnt(x->l) + get_cnt(x->r) + 1;
}

void split(pnode x, int key, pnode& l, pnode& r, int add = 0) // l = tree[0:key]
{
    if (!x)
        return void(l = r = nullptr);
    int x_key = get_cnt(x->l) + add;
    if (key <= x_key)
        split(x->l, key, l, x->l, add), r = x;
    else
        split(x->r, key, x->r, r, add + get_cnt(x->l) + 1), l = x;
    upd_cnt(x);
}

void merge(pnode& t, pnode l, pnode r)
{
    if (!l || !r)
        t = l ? l : r;
    else if (l->prio > r->prio)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    upd_cnt(t);
}


int get(pnode root, int pos, int add=0)
{
    int real_key = get_cnt(root->l) + add;
    if (real_key == pos) return root->key;
    if (pos <= real_key) return get(root->l, pos, add);
    return get(root->r, pos, add + get_cnt(root->l) + 1);
}

void insert(pnode& root, int pos, int val)
{
    pnode l, r;
    split(root, pos, l, r);
    pnode new_node = new node(val);
    merge(l, l, new_node);
    merge(root, l, r);
}

void erase(pnode& root, int pos)
{
    pnode l, r;
    split(root, pos+1, l, r);
    pnode _;
    split(l, pos, l, _);
    merge(root, l, r);
}

void print_tree(pnode root, int add=0)
{
    if (root->l) print_tree(root->l, add);
    cout << "node " << add + get_cnt(root->l) << ": " << root->key << "\n";
    if (root->r) print_tree(root->r, add + get_cnt(root->l) + 1);
}

signed main()
{
    fast();

    int q;
    cin >> q;

    pnode root = nullptr;
    while (q--)
    {
        int t;
        cin >> t;
        if (t==0)
        {
            int p, v;
            cin >> p >> v;
            insert(root, p, v);
        }
        else if (t==1)
        {
            int p;
            cin >> p;
            erase(root, p);
        }
        else
        {
            int p;
            cin >> p;
            cout << get(root, p) << "\n";
        }
    }
    flush(cout);
    _Exit(0); // fsanitizer hates him
    //return 0;
}
