#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
constexpr uli P = 998244353;
constexpr uli ksm(uli a, uli n) {
  uli ans = 1;
  while (n) {
    if (n & 1) (ans *= a) %= P;
    (a *= a) %= P;
    n >>= 1;
  }
  return ans;
}
constexpr uli PX = ksm(2, P - 2);
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t a, b, k;
  cin >> a >> b >> k;
  uli x = 1;
  for (size_t i = 1; i <= k; i++) {
    if (i % a == 0) (x *= 2) %= P;
    if (i % b == 0) x == 1 ? x = 1 : (x *= PX) %= P;
  }
  cout << x;
  return 0;
}