#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned long long int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 998244353;
constexpr ui fastpow(ui a, ui n) {
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
    ui a, b, c;
    cin >> a >> b >> c;
    if (a < b) swap(a, b);
    if (a == c) {
      ui x = fastpow(10, b - 1), y = fastpow(10, b), z = fastpow(10, a - 1),
         w = fastpow(10, a);
      cout << (uli(y + P - x) * uli(w + P - z) % P + P -
               (y * (y - 1ull) / 2 % P + P -
                x * (x - 1ull) / (a == b ? 1 : 2) % P) %
                   P) %
                  P
           << '\n';
    } else if (a + 1 == c) {
      ui x = fastpow(10, b - 1), y = fastpow(10, b);
      cout << (y * (y - 1ull) / 2 % P + P -
               x * (x - 1ull) / (a == b ? 1 : 2) % P) %
                  P
           << '\n';
    } else
      cout << "0\n";
  }
  return 0;
}