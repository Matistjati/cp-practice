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
    for (int i = 0; i < n-1; i++)
    {
        int a = Int(0, n-1);
        Space();
        int b = Int(0, n-1);
        Endl();
        assert(uf.join(a,b));
    }
    
    for (int i = 0; i < q; i++)
    {
        Int(0, n-1); Space();
        Int(0, n-1); Endl();
    }

    Eof();
}
