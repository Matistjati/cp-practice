#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll hi_x = ll(1e9);
void run() {
  ll N = Int(0LL, Arg("maxn")); Space();
  ll M = Int(1LL, Arg("maxm")); Space();
  ll D = Int(1LL, hi_x); Endl();
  bool increasing = (bool)Arg("increasing");
  SpacedInts(N, 1LL, hi_x);
  vector<ll> line = SpacedInts(M, 1LL, hi_x);

  rep(i,0,M-1) {
      if (increasing) assert(line[i+1]>=line[i]);
  };
  Eof();
}
