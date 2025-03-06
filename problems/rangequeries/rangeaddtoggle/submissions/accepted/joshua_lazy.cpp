#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
const int inf = int(1e18);

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

struct Tree
{
	vi tree;
	vi lazy;
	Tree(int n) : tree(n*4), lazy(n*4) {}

	void put_node(int x, int l, int r, int v)
	{
		tree[x] += (r - l + 1) * v;
		lazy[x] += v;
	}
	void push(int x, int l, int r)
	{
		int mid = (l + r) / 2;
		put_node(x * 2, l, mid, lazy[x]);
		put_node(x * 2 + 1, mid + 1, r, lazy[x]);
		lazy[x] = 0;
	}

	void add(int x, int l, int r, int ql, int qr, int v)
	{
		if (r < ql || l > qr) return;
		if (l >= ql && r <= qr)
		{
			return put_node(x, l, r, v);
		}
		push(x, l, r);
		int mid = (l + r) / 2;
		add(x * 2, l, mid, ql, qr, v);
		add(x * 2 + 1, mid + 1, r, ql, qr, v);
		tree[x] = tree[x * 2] + tree[x * 2 + 1];
	}

	int query(int x, int l, int r, int i)
	{
		if (l == r) return tree[x];
		push(x, l, r);
		int mid = (l + r) / 2;
		if (i <= mid) return query(x * 2, l, mid, i);
		return query(x * 2 + 1, mid + 1, r, i);
	}
};

signed main()
{
	fast();

	int n, q;
	cin >> n >> q;
	vi nums(n);
	vi active(n);
	vi num_at_activation(n);
	Tree tree(n);

	while (q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int i;
			cin >> i;
			if (active[i])
			{
				int v = tree.query(1, 0, n - 1, i);
				nums[i] += v - num_at_activation[i];
				num_at_activation[i] = v;
			}
			cout << nums[i] << "\n";
		}
		else if (t == 2)
		{
			int l, r, v;
			cin >> l >> r >> v;
			tree.add(1, 0, n-1, l, r, v);
		}
		else
		{
			int i;
			cin >> i;
			int v = tree.query(1, 0, n - 1, i);
			if (active[i])
			{
				nums[i] += v - num_at_activation[i];
			}
			num_at_activation[i] = v;

			active[i] ^= 1;
		}
	}
    rep(i,n)
    {
        if (active[i])
        {
            int v = tree.query(1, 0, n - 1, i);
            nums[i] += v - num_at_activation[i];
            num_at_activation[i] = v;
        }
        cout << nums[i] << " ";
    }
    cout << "\n";

	return 0;
}
