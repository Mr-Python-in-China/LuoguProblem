#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<ui> t(n);
  for (ui& i : t) cin >> i;
  vector<vector<vector<ui>>> floyd(
      n + 1, vector<vector<ui>>(n, vector<ui>(n, 0x7fffffff)));
  vector<vector<ui>>& mp(floyd[0]);
  for (size_t i = 0; i < n; i++) mp[i][i] = 0;
  while (m--) {
    size_t x, y;
    ui z;
    cin >> x >> y >> z;
    mp[x][y] = mp[y][x] = z;
  }
  for (size_t k = 1; k <= n; k++)
    for (ui i = 0; i < n; i++)
      for (ui j = 0; j < n; j++)
        floyd[k][i][j] = min(floyd[k - 1][i][j],
                             floyd[k - 1][i][k - 1] + floyd[k - 1][k - 1][j]);
#ifdef debug
  for (size_t i = 0; i <= n; i++)
    for (size_t j = 0; j < n; j++) {
      for (size_t k = 0; k < n; k++) cout << floyd[i][j][k] << ' ';
      cout << '\n';
    }
#endif
  size_t q;
  cin >> q;
  while (q--) {
    size_t x, y, d;
    cin >> x >> y >> d;
    size_t tmp = upper_bound(t.begin(), t.end(), d) - t.begin();
    cout << (t[x] > d || t[y] > d || floyd[tmp][x][y] >= 0x7fffffff
                 ? -1
                 : int(floyd[tmp][x][y]))
         << '\n';
  }
  return 0;
}