#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct animal {
  ui t, x, y;
};
template <typename T> T abs_minus(T a, T b) { return max(a, b) - min(a, b); }
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> m >> n;
  vector<animal> a(n);
  for (animal& i : a) cin >> i.t >> i.x >> i.y;
  sort(a.begin(), a.end(),
       [](animal const& a, animal const& b) { return a.t < b.t; });
  vector<ui> f(n);
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < i; ++j)
      if (abs_minus(a[i].x, a[j].x) + abs_minus(a[i].y, a[j].y) + a[j].t <=
          a[i].t)
        f[i] = max(f[i], f[j]);
    ++f[i];
  }
  ui ans = 0;
  for (ui i : f) ans = max(i, ans);
  cout << ans;
  return 0;
}