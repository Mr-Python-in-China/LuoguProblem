#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
uli constexpr P = 998244353;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T, id;
  cin >> T >> id;
  while (T--) {
    size_t n, m;
    bool enble_c, enble_f;
    uli ansc = 0, ansf = 0;
    cin >> n >> m >> enble_c >> enble_f;
    vector<vector<bool>> mp(n, vector<bool>(m));
    for (vector<bool>& i : mp)
      for (vector<bool>::reference j : i) {
        char c;
        cin >> c;
        j = c == '0';
      }
    vector<vector<uli>> count_line_rtol(n, vector<uli>(m));
    for (size_t i = 0; i < n; ++i) {
      if (mp[i][m - 1]) count_line_rtol[i][m - 1] = 1;
      for (size_t j = m - 2; j < m; --j)
        count_line_rtol[i][j] = mp[i][j] ? count_line_rtol[i][j + 1] + 1 : 0;
    }
    vector<vector<uli>> ans_c_dl(n, vector<uli>(m));
    for (size_t j = 0; j < m; ++j) {
      uli sum = mp[0][j] ? count_line_rtol[0][j] - 1 : 0;
      for (size_t i = 1; i < n; ++i)
        if (mp[i][j]) {
          (ansc +=
           (ans_c_dl[i][j] =
                (sum - (mp[i - 1][j] ? count_line_rtol[i - 1][j] - 1 : 0)) *
                (count_line_rtol[i][j] - 1)) %= P) %= P;
          (sum += count_line_rtol[i][j] - 1) %= P;
        } else
          sum = 0;
    }
    for (size_t j = 0; j < m; ++j) {
      uli len = mp[n - 1][j];
      for (size_t i = n - 2; i < n; --i)
        if (mp[i][j])
          (ansf += ans_c_dl[i][j] * len++) %= P;
        else
          len = 0;
    }
    cout << ansc * enble_c << ' ' << ansf * enble_f << '\n';
  }
  return 0;
}