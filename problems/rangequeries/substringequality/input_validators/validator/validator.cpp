#include "validator.h"
#include <set>

void run() {
    int noupdates = Arg("noupdate", 0);


    string s = Line();
    assert(s.size()<=int(1e5));
    int n = s.size();
    int q = Int(1, int(1e5));
    Endl();

    for (int i = 0; i < q; i++)
    {
        int t = Int(0,1);
        Space();
        if (t==1)
        {
            assert(!noupdates);
            Int(0,n-1);
            Space();
            char c = Char();
            assert(c>='a'&&c<='z');
        }
        else
        {
            int l = Int(0, n-1);
            Space();
            Int(l, n-1);
            Space();
            l = Int(0, n-1);
            Space();
            Int(l, n-1);
        }
        Endl();
    }

    Eof();
}
