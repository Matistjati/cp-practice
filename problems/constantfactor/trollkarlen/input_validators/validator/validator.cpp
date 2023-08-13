#include "validator.h"
#include <set>

void run() {

    int n = Int(1, Arg("maxn")); Endl();

    int hi = Arg("maxv", int(1e9));
    for (int i = 0; i < n; i++)
    {
        int t = Int(1, 2); Space();
        int l = Int(1, hi); Space();
        int r = Int(1, hi); Endl();
    }

    Eof();
}
