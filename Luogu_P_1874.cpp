#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string s;
  ui n;
  cin >> s >> n;
  vector<vector<ui>> c(s.size(),
                       vector<ui>(s.size() + 1, numeric_limits<ui>::max() / 2));
  for (size_t i = 0; i < s.size(); ++i)
    for (size_t j = i + 1;
         j <= s.size() && stoi(string(s.begin() + i, s.begin() + j)) <= n; ++j)
      c[i][j] = stoi(string(s.begin() + i, s.begin() + j));
  vector<vector<ui>> f(s.size(),
                       vector<ui>(n + 1, numeric_limits<ui>::max() / 2));
  for (size_t i = 0; i < s.size() && c[0][i + 1] <= n; ++i)
    f[i][c[0][i + 1]] = 0;
  for (size_t i = 0; i < s.size(); ++i)
    for (size_t t = 0; t <= n; ++t)
      for (size_t j = i - 1; j < s.size() && c[j + 1][i + 1] <= n; --j)
        if (c[j + 1][i + 1] <= t)
          f[i][t] = min(f[i][t], f[j][t - c[j + 1][i + 1]] + 1);
  f[s.size() - 1][n] != numeric_limits<ui>::max() / 2
      ? cout << f[s.size() - 1][n]
      : cout << "-1";
  return 0;
}