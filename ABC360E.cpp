#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
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
  ui n;
  size_t k;
  cin >> n >> k;
  uli p0 = 1, p1 = 0;
  ui const d1 = 2 * fastpow(uli(n) * n % P, P - 2) % P,
           d0 = (1 + P - d1 * uli(n - 1) % P) % P;
  while (k--)
    tie(p0, p1) =
        make_tuple((p0 * d0 % P + p1 * d1 % P * (n - 1) % P) % P,
                   (p1 * d0 % P + p1 * d1 % P * (n - 2) % P + p0 * d1 % P) % P);
  cout << ((uli(n - 1) * n / 2) % P * p1 + 1) % P;
  return 0;
}