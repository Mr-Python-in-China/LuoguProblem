#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 20100403;
ui frac(ui n) {
  static ui f[size_t(1e7 + 1)];
  return f[n] ? f[n] : (f[n] = n == 0 ? 1 : frac(n - 1) * uli(n) % P);
}
ui fastpow(ui a, ui n) {
  uli ans = 1;
  while (n) {
    if (n & 1) (ans *= a) %= P;
    a = uli(a) * a % P;
    n >>= 1;
  }
  return ans;
}
ui inv(ui a) { return fastpow(a, P - 2); }
ui c(ui n, ui m) {
  return uli(frac(n)) * inv(frac(m)) % P * inv(frac(n - m)) % P;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  cout << (c(n + m, m) + P - c(n + m, m - 1)) % P;
  return 0;
}