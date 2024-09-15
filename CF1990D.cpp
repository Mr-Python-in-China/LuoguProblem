#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr auto c(ui x) { return x <= 4 ? (1u << x) - 1 : (1u << 4) - 1; }
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<ui> a(n);
    for (ui &i : a) cin >> i;
    array<ui, 1 << 4> f;
    f.fill(numeric_limits<ui>::max() / 2);
    f[c(a[0])] = bool(a[0]);
    if (a[0] <= 4) f[0] = 0;
    for (size_t i = 1; i < n; ++i) {
      array<ui, 1 << 4> g;
      g.fill(numeric_limits<ui>::max() / 2);
      g[c(a[i])] = f[c(a[i - 1])] + bool(a[i]);
      if (a[i] <= 4) {
        g[0] = f[c(a[i - 1])];
        for (ui j : {0b0000, 0b0011, 0b0110, 0b0111, 0b1100, 0b1110, 0b1111}) {
          for (ui k = 0; k < f.size(); ++k)
            if (((j | k) & c(a[i - 1])) == c(a[i - 1]))
              g[j & c(a[i])] =
                  min(g[j & c(a[i])], f[k] + (__builtin_popcount(j) + 1) / 2);
        }
      }
      f = g;
    }
    cout << f[c(a.back())] << '\n';
  }
  return 0;
}