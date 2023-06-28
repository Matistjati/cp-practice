#include "validator.h"
#include <set>

void run() {
    int maxQ = Arg("maxq", int(1e5));
    int tinyupdate = Arg("tinyupdate", 0);
    int tinyquery = Arg("tinyquery", 0);

    int q = Int(1, maxQ); Endl();

    for (int i = 0; i < q; i++)
    {
        int t = Int(0, 1); Space();
        int l = Int(0, int(1e9-1)); Space();
        int r = Int(l, int(1e9-1));
        if (tinyquery&&!t) assert(l==r);
        if (tinyupdate&&t) assert(l==r);

        if (t==1)
        {
            Space();
            Int(1, int(1e9));
        }

        Endl();
    }

    Eof();
}
