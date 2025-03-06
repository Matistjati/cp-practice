#include <bits/allocator.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <immintrin.h>
using namespace std;

typedef long long ll;
#define int ll

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> p2;

#define rep(i, high) for (int i = 0; i < (high); i++)
#define repp(i, low, high) for (int i = (low); i < (high); i++)
#define repe(i, container) for (auto& i : container)
#define sz(container) ((int)container.size())
#define all(x) begin(x),end(x)

inline void fast() { cin.tie(0)->sync_with_stdio(0); }

#if _LOCAL
#define assert(x) if (!(x)) __debugbreak()
#endif

signed main()
{
	fast();

	int n, q;
	cin >> n >> q;
	vi nums(n);
	vi active(n);

	while (q--)
	{
		int t;
		cin >> t;
		if (t==1)
		{
			int i;
			cin >> i;
			cout << nums[i] << "\n";
		}
		else if (t==2)
		{
			int l,r, v;
			cin >> l >> r >> v;
			int i = l;
			__m256i vec_v = _mm256_set1_epi64x(v);

			#pragma GCC unroll 8
			for (; i + 3 <= r; i += 4) {
				__m256i vec_nums = _mm256_loadu_si256((__m256i*)&nums[i]);
				__m256i vec_active = _mm256_loadu_si256((__m256i*)&active[i]);

				__m256i vec_mul = _mm256_and_si256(vec_active, vec_v);
				__m256i vec_result = _mm256_add_epi64(vec_nums, vec_mul);

				_mm256_storeu_si256((__m256i*)&nums[i], vec_result);
			}

			for (; i <= r; ++i) {
				nums[i] += active[i] & v;
			}
		}
		else
		{
			int i;
			cin >> i;
			active[i] ^= LLONG_MAX;
		}
	}
	rep(i,n) cout << nums[i] << " ";

	return 0;
}
