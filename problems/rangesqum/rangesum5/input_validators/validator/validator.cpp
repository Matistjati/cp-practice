#include "validator.h"
#include <set>

void run() {
    int n = Int(1, int(2e5));
    Space();
    int q = Int(1, int(2e5)); Endl();

    for (int i = 0; i < q; i++)
    {
        int t = Int(0, 2); Space();
        if (t==1)
        {
            int l = Int(0, n-1);
            Space();
            Int(l, n-1);
        }
        if (t==2)
        {
            int l = Int(0, n-1);
            Space();
            Int(l, n-1);
            Space();
            Int(1, int(1e9));
        }

        Endl();
    }

    Eof();
}
