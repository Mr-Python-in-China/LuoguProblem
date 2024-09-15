#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
size_t solve(size_t n, size_t m, size_t k, vector<vector<bool>> const& a) {
  vector<vector<ui>> hc(n, vector<ui>(m)),  // 行
      lc(n, vector<ui>(m)),                 // 列
      xc(n, vector<ui>(m));                 // 斜
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < m && j < k; ++j) hc[i][0] += a[i][j];
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 1; j < m; ++j)
      hc[i][j] =
          hc[i][j - 1] - a[i][j - 1] + (j + k - 1 < m ? a[i][j + k - 1] : 0);

  for (size_t j = 0; j < m; ++j)
    for (size_t i = 0; i < n && i < k; ++i) lc[0][j] += a[i][j];
  for (size_t j = 0; j < m; ++j)
    for (size_t i = 1; i < n; ++i)
      lc[i][j] =
          lc[i - 1][j] - a[i - 1][j] + (i + k - 1 < n ? a[i + k - 1][j] : 0);

  for (size_t i = 0; i <) vector<vector<ui>> ans(n, vector<ui>(m));
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j + i < k; ++j) ans[0][0] += a[i][j];
  // for (size_t j=1;j<m;++j)
  return 0;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, m, k;
    cin >> n >> m >> k;
    vector<vector<bool>> arr(n, vector<bool>(m));
    for (vector<bool>& i : arr)
      for (vector<bool>::reference j : i) {
        char c;
        cin >> c;
        j = c == '#';
      }
    solve(n, m, k, arr);
  }
  return 0;
}