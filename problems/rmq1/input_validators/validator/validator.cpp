#include "validator.h"
#include <set>

void run() {
    int maxN = Arg("maxn", 1e5);
    int maxQ = Arg("maxq", 1e5);

    int n = Int(1, maxN); Space(); int q = Int(0, maxQ); Endl();

    SpacedInts(n, 0, int(1e9));
    for (int i = 0; i < q; i++)
    {
        int l = Int(0, n-1); Space();
        int r = Int(l, n-1);
        Endl();
    }

    Eof();
}
