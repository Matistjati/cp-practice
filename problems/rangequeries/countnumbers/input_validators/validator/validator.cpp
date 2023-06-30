#include "validator.h"
#include <set>

void run() {
    int n = Int(1, int(1e5));
    Space();
    int q = Int(1, int(1e5));
    Endl();
    SpacedInts(n, 0, int(1e9));

    for (int i = 0; i < q; i++)
    {
        int l = Int(0, n-1);
        Space();
        int r = Int(l, n-1);
        Space();
        int v = Int(0, int(1e9));
        Endl();
    }

    Eof();
}
