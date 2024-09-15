#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 1e9 + 7;
constexpr size_t N = 1e6 + 1;
ui f(ui x) {
  static array<ui, N> mem = {};
  if (mem[x]) return mem[x];
  if (x == 0) return mem[x] = 1;
  if (x == 1) return mem[x] = 0;
  return mem[x] = uli(x - 1) * (f(x - 1) + f(x - 2)) % P;
}
ui frac(ui x) {
  static array<ui, N> mem = {};
  if (mem[x]) return mem[x];
  if (x == 0) return 1;
  return mem[x] = uli(x) * frac(x - 1) % P;
}
ui quick_pow(ui a, ui n) {
  ui ans = 1;
  while (n) {
    if (n & 1) ans = uli(ans) * a % P;
    a = uli(a) * a % P;
    n >>= 1;
  }
  return ans;
}
ui inv(ui x) { return quick_pow(x, P - 2); }
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    ui n, m;
    cin >> n >> m;
    cout << uli(uli(frac(n)) * inv(uli(frac(m)) * frac(n - m) % P) % P) *
                f(n - m) % P
         << '\n';
  }
  return 0;
}