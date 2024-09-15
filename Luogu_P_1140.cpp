#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
signed constexpr TABLE[5][5] = {
    { 0, -3, -4, -2, -1},
    {-3,  5, -1, -2, -1},
    {-4, -1,  5, -3, -2},
    {-2, -2, -3,  5, -2},
    {-1, -1, -2, -2,  5}
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  string s, t;
  cin >> n >> s >> m >> t;
  for (char& i : s)
    i = i == 'A' ? 1 : i == 'C' ? 2 : i == 'G' ? 3 : i == 'T' ? 4 : throw;
  for (char& i : t)
    i = i == 'A' ? 1 : i == 'C' ? 2 : i == 'G' ? 3 : i == 'T' ? 4 : throw;
  vector<vector<int>> f(n + 1,
                        vector<int>(m + 1, numeric_limits<int>::min() / 2));
  f[0][0] = 0;
  for (size_t i = 1; i <= n; ++i) f[i][0] = f[i - 1][0] + TABLE[s[i - 1]][0];
  for (size_t i = 1; i <= m; ++i) f[0][i] = f[0][i - 1] + TABLE[0][t[i - 1]];
  for (size_t i = 1; i <= n; ++i)
    for (size_t j = 1; j <= m; ++j)
      f[i][j] = max({f[i - 1][j] + TABLE[s[i - 1]][0],
                     f[i][j - 1] + TABLE[0][t[j - 1]],
                     f[i - 1][j - 1] + TABLE[s[i - 1]][t[j - 1]]});
  cout << f[n][m];
  return 0;
}