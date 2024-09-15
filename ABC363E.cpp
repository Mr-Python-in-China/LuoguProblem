#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  ui y;
  cin >> n >> m >> y;
  vector<vector<ui>> mp(n, vector<ui>(m));
  array<vector<pair<size_t, size_t>>, size_t(1e5 + 1)> ev;
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < m; ++j) {
      cin >> mp[i][j];
      if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
        ev[mp[i][j]].emplace_back(i, j);
    }
  vector<vector<bool>> filled(n, vector<bool>(m));
  size_t live = n * m;
  for (ui h = 1; h <= y; ++h) {
    queue<pair<size_t, size_t>> q;
    for (pair<size_t, size_t> const &i : ev[h])
      if (!filled[i.first][i.second])
        filled[i.first][i.second] = true, --live, q.emplace(i);
    while (!q.empty()) {
      pair<size_t, size_t> p = q.front();
      q.pop();
      for (auto i : array<pair<int, int>, 4>{
               {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}
      }) {
        pair<size_t, size_t> np = {p.first + i.first, p.second + i.second};
        if (np.first < n && np.second < m && !filled[np.first][np.second])
          if (mp[np.first][np.second] <= h)
            filled[np.first][np.second] = true, --live, q.emplace(np);
          else
            ev[mp[np.first][np.second]].emplace_back(np);
      }
    }
    cout << live << '\n';
  }
  return 0;
}