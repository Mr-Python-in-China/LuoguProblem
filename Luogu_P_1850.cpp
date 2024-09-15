#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr double Inf = numeric_limits<double>::infinity();
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, v, e;
  cin >> n >> m >> v >> e;
  vector<pair<size_t, size_t>> c(n);
  vector<double> p(n);
  vector<vector<ui>> dis(v, vector<ui>(v, numeric_limits<ui>::max() / 2));
  for (size_t i = 0; i < v; ++i) dis[i][i] = 0;
  for (pair<size_t, size_t> &i : c) cin >> i.first, --i.first;
  for (pair<size_t, size_t> &i : c) cin >> i.second, --i.second;
  for (double &i : p) cin >> i;
  while (e--) {
    size_t x, y;
    ui z;
    cin >> x >> y >> z;
    --x, --y;
    dis[x][y] = min(dis[x][y], z), dis[y][x] = min(dis[y][x], z);
  }
  for (size_t k = 0; k < v; ++k)
    for (size_t i = 0; i < v; ++i)
      for (size_t j = 0; j < v; ++j)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  vector<pair<double, double>> f(m + 1, {Inf, Inf});
  f[0].first = 0;
  if (m > 0) f[1].second = 0;
  for (size_t d = 1; d < n; ++d) {
    vector<pair<double, double>> g(m + 1, {Inf, Inf});
    {
      constexpr size_t i = 0;
      g[i].first =
          min({f[i].first + dis[c[d - 1].first][c[d].first],
               f[i].second + p[d - 1] * dis[c[d - 1].second][c[d].first] +
                   (1 - p[d - 1]) * dis[c[d - 1].first][c[d].first]});
    }
    for (size_t i = 1; i <= m; ++i) {
      g[i] = {min(f[i].first + dis[c[d - 1].first][c[d].first],
                  f[i].second + p[d - 1] * dis[c[d - 1].second][c[d].first] +
                      (1 - p[d - 1]) * dis[c[d - 1].first][c[d].first]),
              min(f[i - 1].first + p[d] * dis[c[d - 1].first][c[d].second] +
                      (1 - p[d]) * dis[c[d - 1].first][c[d].first],
                  f[i - 1].second +
                      p[d - 1] * p[d] * dis[c[d - 1].second][c[d].second] +
                      (1 - p[d - 1]) * p[d] * dis[c[d - 1].first][c[d].second] +
                      p[d - 1] * (1 - p[d]) * dis[c[d - 1].second][c[d].first] +
                      (1 - p[d - 1]) * (1 - p[d]) *
                          dis[c[d - 1].first][c[d].first])};
    }
    f = g;
  }
  double ans = Inf;
  for (pair<double, double> const &i : f) ans = min({ans, i.first, i.second});
  cout << fixed << setprecision(2) << ans;
  return 0;
}