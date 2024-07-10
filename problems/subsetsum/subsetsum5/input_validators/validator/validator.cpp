#include "validator.h"
#include <set>

void run() {
    int n = Int(1, 4000);
    Space();
    int t = Int(0, int(2e6));
    Endl();

    SpacedInts(n, 0, t);

    Eof();
}
