#include "validator.h"
#include <set>


struct UF {
	vector<int> e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

void run() {
    int n = Int(1, int(2e5));
    Space();
    int q = Int(1, int(2e5)); Endl();

    UF uf(n);
    vector<int> color(n);
    color[0]=0;
    for (int i = 0; i < q; i++)
    {
        int t = Int(0, 1); Space();
        int u = Int(0, n-1); Endl();

        if (t==0)
        {
            assert(color[u]==0);
            color[u]=1;
        }


    }

    Eof();
}
