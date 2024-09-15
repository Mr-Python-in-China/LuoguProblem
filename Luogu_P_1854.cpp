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
  vector<vector<ui>> a(n, vector<ui>(m));
  for (vector<ui>& i : a)
    for (ui& j : i) cin >> j;
  vector<vector<int>> f(n + 1,
                        vector<int>(m + 1, numeric_limits<int>::min() / 2));
  vector<vector<unsigned char>> from(n + 1, vector<unsigned char>(m + 1));
  fill(f[0].begin(), f[0].end(), 0),
      fill(from[0].begin() + 1, from[0].end(), 1);
  for (size_t i = 1; i <= n; ++i)
    for (size_t j = 1; j <= m; ++j)
      f[i][j] = f[i][j - 1] > f[i - 1][j - 1] + int(a[i - 1][j - 1])
                    ? (from[i][j] = 1, f[i][j - 1])
                    : (from[i][j] = 2, f[i - 1][j - 1] + int(a[i - 1][j - 1]));
  cout << f.back().back() << '\n';
  vector<size_t> stk;
  for (pair<size_t, size_t> i = {n, m}; from[i.first][i.second];
       from[i.first][i.second] == 1 ? (--i.second)
                                    : (stk.push_back(i.second--), --i.first));
  for_each(stk.rbegin(), stk.rend(), [](size_t x) { cout << x << ' '; });
  return 0;
}