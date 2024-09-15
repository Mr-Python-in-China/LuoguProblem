#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
ui constexpr P = 998244353;
ui pow2(ui x) {
  static array<ui, size_t(1e7)> mem{1};
  if (mem[x]) return mem[x];
  mem[x] = pow2(x - 1) * 2;
  if (mem[x] >= P) mem[x] -= P;
  return mem[x];
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  uli m;
  cin >> n >> m;
  ui ans = 1;
  map<uli, size_t> pm;
  {
    uli x = m;
    for (ui i = 2; i * i <= m; ++i)
      while (x % i == 0) x /= i, ++pm[i];
    if (x) ++pm[x];
  }
  map<uli, size_t> cnt;
  while (n--) {
    ui x;
    cin >> x;
    if (m % x == 0) ++cnt[x];
  }

  cout << ans;
  return 0;
}