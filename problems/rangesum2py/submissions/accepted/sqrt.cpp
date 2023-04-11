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
    
    int m = 300;
    vl b((n+m-1)/m);
    for (int i = 0; i < n; i++)
        b[i / m] += a[i];
    
    for(int i = 0; i < q; i++){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            ll ans = 0;
            for(int j = l; j <= r;){
                if(j % m == 0 && j + m - 1 <= r){
                    ans += b[j / m];
                    j += m;
                }
                else{
                    ans += a[j];
                    j++;
                }
            }
            cout << ans << endl;
        }
        else{
            b[l / m] += r - a[l];
            a[l] = r;
        }
    }
}
