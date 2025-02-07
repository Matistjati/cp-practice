#include "validator.h"
#include <set>

void run() {
    int n = Int(1, Arg("maxn"));
    Space();
    int q = Int(1, Arg("maxq"));
    Endl();
    SpacedInts(n, 1, int(2e5));

    for (int i = 0; i < q; i++)
    {
        int l = Int(0, n-1);
        Space();
        int r = Int(l, n-1);
        Endl();
    }

    Eof();
}
