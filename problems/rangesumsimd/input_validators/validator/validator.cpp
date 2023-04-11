#include "validator.h"
#include <set>

void run() {
    int maxN = Arg("maxn", -1);
    int maxQ = Arg("maxq", -1);

    int n = Int(1, maxN); Space(); int q = Int(1, maxQ); Endl();

    SpacedInts(n, 1, 100);
    for (int i = 0; i < q; i++)
    {
        int t = Int(1, 2); Space();
        int l = Int(0, n-1); Space();
        if (t == 1) Int(l, n-1);
        else Int(1, 100);
        Endl();
    }

    Eof();
}
