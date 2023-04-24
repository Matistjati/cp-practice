#include "validator.h"
#include <set>

void run() {
    int maxN = Arg("maxn");
    int maxV = Arg("maxv", 100);
    int maxT = Arg("maxt", int(1e5));

    int n = Int(1, maxN); Space(); int t = Int(0, maxN*maxV);Endl();

    SpacedInts(n, 0, maxV);

    Eof();
}
