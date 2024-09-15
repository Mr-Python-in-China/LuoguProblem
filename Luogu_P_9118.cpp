#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> T ksm(T a, T n) {
  T ans = 1;
  while (n) {
    if (n & 1) ans *= a;
    a *= a;
    n >>= 1;
  }
  return ans;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, k, ordered;
  cin >> n >> k;
  if (k == 1) cout << n, exit(0);
  unordered_set<size_t> vis, pow_2;
  for (__int128_t j = max<size_t>(k, 3); (__int128_t(1) << j) <= n; ++j)
    for (__int128_t i = 1, x = 1; x <= n; x = ksm(++i, j)) {
      vis.insert(x);
      if (__int128_t(__builtin_sqrtl(x)) * __int128_t(__builtin_sqrtl(x)) == x)
        pow_2.insert(x);
    }
  cout << vis.size() + (k == 2 ? size_t(__builtin_sqrtl(n)) - pow_2.size() : 0);
  return 0;
}