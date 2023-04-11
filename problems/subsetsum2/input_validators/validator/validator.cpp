#include "validator.h"
#include <set>

void run() {
    int maxN = Arg("maxn");
    int maxV = Arg("maxv", 1000);

    int n = Int(1, maxN); Endl();

    SpacedInts(n, 0, maxV);

    Eof();
}
