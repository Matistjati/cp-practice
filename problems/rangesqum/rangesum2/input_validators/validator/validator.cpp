#include "validator.h"

const int MAX_N = 3e5;
const int MAX_Q = 1e5;
const int MAX_VAL = 1e9;

void run() {
    int maxN = Arg("maxn", MAX_N);
    int maxQ = Arg("maxq", MAX_Q);

    int n = Int(1, maxN); Space(); int q = Int(1, maxQ); Endl();

    SpacedInts(n, 1, MAX_VAL);
    for (int i = 0; i < q; i++)
    {
        int t = Int(1, 2); Space();
        int l = Int(0, n-1); Space();
        if (t == 1) Int(l, n-1);
        else Int(1, MAX_VAL);
        Endl();
    }
}
