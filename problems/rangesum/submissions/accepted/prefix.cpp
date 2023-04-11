#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
const int inf = 0x3f3f3f3f;
const ll linf = 1234567890123456789;
const ll mod = 1000000007;
#define all(x) x.begin(), x.end()
#define debug(x) cerr << (#x) << " = " << (x) << endl
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for(int i = a; i < (b); ++i)


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vl a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vl b(n+1);
    for(int i = 0; i < n; i++){
        b[i+1] = b[i] + a[i];
    }
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << b[r+1] - b[l] << endl;
    }
}
