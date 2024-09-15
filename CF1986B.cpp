#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, m;
    cin >> n >> m;
    vector<vector<ui>> a(n, vector<ui>(m));
    for (vector<ui> &i : a)
      for (ui &j : i) cin >> j;
    for (size_t i = 0; i < n; ++i)
      for (size_t j = 0; j < m; ++j) {
        ui d1 = i - 1 < n ? a[i - 1][j] : 0, d2 = i + 1 < n ? a[i + 1][j] : 0,
           d3 = j - 1 < m ? a[i][j - 1] : 0, d4 = j + 1 < m ? a[i][j + 1] : 0;
        a[i][j] = min(a[i][j], max({d1, d2, d3, d4}));
      }
    for (vector<ui> const &i : a) {
      for (ui j : i) cout << j << ' ';
      cout.put('\n');
    }
  }
  return 0;
}