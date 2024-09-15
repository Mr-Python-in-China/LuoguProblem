#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui x, y;
  cin >> n >> x >> y;
  vector<pair<ui, ui>> p(n);
  for (pair<ui, ui>& i : p) cin >> i.first >> i.second;
  vector<vector<double>> dist(
      n + 4, vector<double>(n + 4, numeric_limits<double>::infinity()));
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < n; ++j)
      dist[i][j] = dist[j][i] = sqrt(
          (max(p[i].first, p[j].first) - min(p[i].first, p[j].first)) *
              (max(p[i].first, p[j].first) - min(p[i].first, p[j].first)) +
          (max(p[i].second, p[j].second) - min(p[i].second, p[j].second)) *
              (max(p[i].second, p[j].second) - min(p[i].second, p[j].second)));
  dist[n + 0][n + 1] = dist[n + 1][n + 0] = dist[n + 2][n + 3] =
      dist[n + 3][n + 2] = dist[n + 0][n + 0] = dist[n + 1][n + 1] =
          dist[n + 2][n + 2] = dist[n + 3][n + 3] = 0;
  for (size_t i = 0; i < n; ++i)
    dist[i][n + 0] = dist[n + 0][i] = (p[i].first - 1) * 2;
  for (size_t i = 0; i < n; ++i)
    dist[i][n + 1] = dist[n + 1][i] = (y - p[i].second) * 2;
  for (size_t i = 0; i < n; ++i)
    dist[i][n + 2] = dist[n + 2][i] = (x - p[i].first) * 2;
  for (size_t i = 0; i < n; ++i)
    dist[i][n + 3] = dist[n + 3][i] = (p[i].second - 1) * 2;
  double l = 0, r = 1e10;
  while (r - l > 1e-3) {
    double mid = (l + r) / 2;
    vector<bool> vis(n + 4);
    vis[n + 0] = true;
    queue<size_t> q({n + 0});
    while (!q.empty()) {
      size_t p = q.front();
      q.pop();
      for (size_t i = 0; i < n + 4; ++i)
        if (!vis[i] && dist[p][i] < mid * 2) q.push(i), vis[i] = true;
    }
    (vis[n + 2] ? r : l) = mid;
  }
  cout << fixed << setprecision(2) << l;
  return 0;
}