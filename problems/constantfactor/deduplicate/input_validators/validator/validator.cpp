#include "validator.h"
#include <set>

void run() {
    int q = Int(1, Arg("q")); Endl();
    for (int i = 0; i < q; i++)
    {
        int k = Int(0, 1<<20); Space();
        int a = Int(0, 1<<20); Space();
        int c = Int(0, 1<<20); Space();
        int m = Int(1, 20);    Space();
        int n = Int(1, int(1e5)); Endl();
        assert(k<(1<<m));
        assert(a<(1<<m));
        assert(c<(1<<m));
    }

    Eof();
}
