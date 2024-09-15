#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 10;
ui quick_pow(ui a, uli n) {
  ui ans = 1;
  while (n) {
    if (n & 1) ans = uli(ans) * a % P;
    a = uli(a) * a % P;
    n >>= 1;
  }
  return ans;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    uli n, k, m;
    cin >> n >> m >> k;
    if (n < k)
      cout << quick_pow(2, n) << '\n';
    else {
      n -= k, m -= k;
      uli d = n % m;
      cout << (m == 1 ? 0 : quick_pow(2, d + k)) << '\n';
    }
  }
  return 0;
}