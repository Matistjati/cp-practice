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

#pragma GCC target ("avx2") // or sse4.1
#include "immintrin.h" /** keep-include */

typedef __m256i mi;
#define L(x) _mm256_loadu_si256((mi*)&(x))

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < q; i++){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            mi ansv = _mm256_setzero_si256();
            int j = l;
            for(; j+7 <= r; j+=8){
                ansv = _mm256_add_epi32(ansv, L(a[j]));
            }
            int ans = 0;
            for(int k = 0; k < 8; k++)
                ans += ((int*)&ansv)[k];
            for(; j <= r; j++){
                ans += a[j];
            }
            cout << ans << endl;
        }
        else{
            a[l] = r;
        }
    }
}
