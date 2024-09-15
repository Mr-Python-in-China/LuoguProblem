#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<vector<bool>> mp(n, vector<bool>(m));
  for (vector<bool>& i : mp)
    for (vector<bool>::reference j : i) {
      char c;
      cin >> c;
      j = c == '.';
    }
  vector<vector<bool>> vis(n, vector<bool>(m));
  ui ans = 1;
  auto check_ceil = [&mp, n, m](size_t x, size_t y) {
    auto f = [&mp, n, m](size_t x, size_t y) {
      return x < n && y < m ? mp[x][y] : true;
    };
    return f(x, y) && f(x - 1, y) && f(x, y - 1) && f(x + 1, y) && f(x, y + 1);
  };
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < m; ++j)
      if (check_ceil(i, j) && !vis[i][j]) {
        ui cnt = 1;
        vis[i][j] = true;
        queue<pair<size_t, size_t>> q({
            {i, j}
        });
        vector<pair<size_t, size_t>> tmp;
        while (!q.empty()) {
          pair<size_t, size_t> p = q.front();
          q.pop();
          for (auto i : {
                   pair<int, int>{ 1,  0},
                    pair<int, int>{ 0,  1},
                   pair<int, int>{-1,  0},
                    pair<int, int>{ 0, -1}
          }) {
            pair<size_t, size_t> np(p.first + i.first, p.second + i.second);
            if (np.first < n && np.second < m && !vis[np.first][np.second]) {
              vis[np.first][np.second] = true, ++cnt;
              if (!check_ceil(np.first, np.second))
                tmp.emplace_back(np);
              else
                q.push(np);
            }
          }
        }
        ans = max(cnt, ans);
        for (auto const& i : tmp) vis[i.first][i.second] = false;
      }
  cout << ans;
  return 0;
}