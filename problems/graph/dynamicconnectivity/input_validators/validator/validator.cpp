#include "validator.h"
#include <set>

void run() {
    int n = Int(1, int(2e5));
    Space();
    int q = Int(1, int(2e5)); Endl();

    set<pair<int,int>> edges;

    for (int i = 0; i < q; i++)
    {
        int t = Int(0, 2); Space();
        int a = Int(0, n-1); Space();
        int b = Int(0, n-1); Endl();

        assert(a!=b);
        if (t!=2)
        {
            if (a>b) swap(a,b);
            if (t==0)
            {
                assert(edges.find(pair<int,int>(a,b))==edges.end());
                edges.insert(pair<int,int>(a,b));
            }
            else
            {
                assert(edges.find(pair<int,int>(a,b))!=edges.end());
                edges.erase(pair<int,int>(a,b));
            }
        }


    }

    Eof();
}
