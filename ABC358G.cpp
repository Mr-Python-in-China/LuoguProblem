#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t h, w, k, x, y;
  cin >> h >> w >> k >> x >> y;
  --x, --y;
  vector<vector<ui>> a(h, vector<ui>(w));
  for (vector<ui> &i : a)
    for (ui &j : i) cin >> j;
  vector<vector<uli>> f(h, vector<uli>(w));
  size_t t = min(size_t(1e7) / (h * w), k);
  for (size_t d = 1; d <= t; ++d) {
    vector<vector<uli>> g(f);
    for (size_t i = 0; i < h; ++i)
      for (size_t j = 0; j < w; ++j)
        if ((max(i, x) - min(i, x)) + (max(j, y) - min(j, y)) <= d) {
          if (i + 1 < h && j < w) g[i][j] = max(g[i][j], f[i + 1][j]);
          if (i - 1 < h && j < w) g[i][j] = max(g[i][j], f[i - 1][j]);
          if (i < h && j + 1 < w) g[i][j] = max(g[i][j], f[i][j + 1]);
          if (i < h && j - 1 < w) g[i][j] = max(g[i][j], f[i][j - 1]);
          g[i][j] += a[i][j];
        }
    f = g;
  }
  uli ans = 0;
  for (size_t i = 0; i < h; ++i)
    for (size_t j = 0; j < w; ++j) {
      ans = max(ans, f[i][j] + a[i][j] * (k - t));
    }
  cout << ans;
  return 0;
}