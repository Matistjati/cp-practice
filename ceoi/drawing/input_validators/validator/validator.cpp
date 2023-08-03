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

struct UF
{
  vi par;
  UF(int n) : par(n)
  {
    rep(i,0,n) par[i]=i;
  }
  int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
  int merge(int a, int b)
  {
    a=find(a); b=find(b);
    if(a==b) return 0;
    par[b] = a;
    return 1;
  }
};

ll hi_coord = ll(1e9);
void run() {
  ll N = Int(Arg("minn", 1LL), Arg("maxn")); Endl();
  bool convex = (bool)Arg("convex", 0); // Won't verify if a solution exists in this case, since it is extremely nontrivial 
  vi deg(N);
  int numcomponents = N;
  UF uf(N);
  rep(i,0,N-1)
  {
    ll a = Int(1,N); Space();
    ll b = Int(1,N); Endl();
    assert(a!=b);
    a--; b--;
    deg[a]++;
    deg[b]++;
    numcomponents -= uf.merge(a,b);
  }
  assert(numcomponents==1);
  rep(i,0,N) assert(deg[i]<=3);

  set<pii> seen;
  rep(i,0,N)
  {
    ll a = Int(0,hi_coord); Space();
    ll b = Int(0,hi_coord); Endl();
    pii pos = pii(a,b);
    assert(seen.find(pos)==seen.end());
    seen.insert(pos);
  } // Won't verify non-colinearity of any 3 points

  Eof();
}
