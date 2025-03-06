#include "validator.h"
#include <set>

void run() {
    int n = Int(1, int(4e5));
    Space();
    int q = Int(1, int(4e5));
    Endl();

    for (int i = 0; i < q; i++)
    {
        int t = Int(1,3);
        Space();
        if (t==1)
        {
            Int(0,n-1);
        }
        else if (t==2)
        {
            int l = Int(0,n-1);
            Space();
            int r = Int(l, n-1);
            Space();
            Int(1, int(1e7));
        }
        else
        {
            Int(0,n-1);
        }
        Endl();
    }

    Eof();
}
