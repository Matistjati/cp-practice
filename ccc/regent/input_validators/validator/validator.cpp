#include "validator.h"
#include <set>

void run() {
    int m = Int(1,40);
    Space();
    int n = Int(1,20);
    Endl();
    SpacedInts(n, 0, 10);
    for (int i = 0; i < m; i++) {
        Int(1, 200);
        Space();
        SpacedInts(n, 0, 10);
    }
    Eof();
}
