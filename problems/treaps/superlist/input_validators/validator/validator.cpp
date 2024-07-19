#include "validator.h"
#include <set>

void run() {
    

    int q = Int(1, int(5e5)); Endl();

    int s = 0;
    for (int i = 0; i < q; i++)
    {
        int t = Int(0, 2); Space();
        if (t==0)
        {
            Int(0, s);
            Space();
            Int(1, int(1e9));
            Endl();
            s++;
        }
        else
        {
            Int(0, s-1);
            if (t==1) s--;
            Endl();
        }
    }

    Eof();
}
