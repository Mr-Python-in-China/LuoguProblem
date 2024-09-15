#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, k;
  cin >> n >> m >> k;
  vector<vector<bool>> front(n, vector<bool>(k)), left(m, vector<bool>(k)),
      up(n, vector<bool>(m));
  for (size_t x = 0; x < k; x++)
    for (size_t y = 0; y < n; y++)
      for (size_t z = 0; z < m; z++) {
        bool v;
        cin >> v;
        if (v)
          front[y][k - x - 1] = left[m - z - 1][k - x - 1] = up[y][m - z - 1] =
              true;
      }
  for (size_t i = 0; i < k; i++) {
    for (size_t j = 0; j < n; j++) cout << front[j][i] << ' ';
    cout << '\n';
  }
  for (size_t i = 0; i < k; i++) {
    for (size_t j = 0; j < m; j++) cout << left[j][i] << ' ';
    cout << '\n';
  }
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++) cout << up[j][i] << ' ';
    cout << '\n';
  }
  return 0;
}