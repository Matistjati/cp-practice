#include "validator.h"
#include <set>

void run() {
    int n = Int(1, int(2e5));
    Space();
    int q = Int(1, int(2e5)); Endl();

    SpacedInts(n, 0, int(1e8));

    int exclude = Arg("exclude");
    for (int i = 0; i < q; i++)
    {
        int t = Int(1, 3); Space();
        assert(t!=exclude);
        if (t==1)
        {
            int l = Int(0, n-1);
            Space();
            Int(l, n-1);
            Space();
            Int(0, int(1e8));
        }
        else if (t==2)
        {
            int l = Int(0, n-1);
            Space();
            Int(l, n-1);
            Space();
            Int(0, int(1e8));
        }
        if (t==3)
        {
            int l = Int(0, n-1);
            Space();
            Int(l, n-1);
        }

        Endl();
    }

    Eof();
}
