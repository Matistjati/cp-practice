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
  ll M = Int(1LL, Arg("maxm")); Endl();

  bool no_alone = (bool)Arg("no_one");
  bool m_large = (bool)Arg("m_large");
  if (m_large) assert(2*N<=M);

  rep(i,0,M) {
    int b = Int(0, N); Space();
    int t = Int(0, N); Endl();
    if (b==0) assert(t==0);
    if (no_alone&&t!=0) assert(b!=0);
  };
  Eof();
}
