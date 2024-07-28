#include "validator.h"
#include <set>

void run() {
    int n = Int(1, int(2e5));
    Space();
    int q = Int(1, int(2e5));
    Endl();
    string s = Line();
    assert(s.size()==n);
    for (int i = 0; i < n; i++) assert(s[i]=='1'||s[i]=='0');

    int exclude = Arg("exclude");
    for (int i = 0; i < q; i++)
    {
        int t = Int(1, 2);
        assert(t!=exclude);
        Space();
        int l = Int(0, n-1);
        Space();
        int r = Int(l, n-1);
        Endl();
    }

    Eof();
}
