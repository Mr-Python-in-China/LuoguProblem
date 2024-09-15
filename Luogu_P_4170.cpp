#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string s;
  cin >> s;
  vector<vector<ui>> f(s.size(),
                       vector<ui>(s.size() + 1, numeric_limits<ui>::max()));
  for (size_t i = 0; i < s.size(); ++i) f[i][i] = 0, f[i][i + 1] = 1;
  for (size_t len = 2; len <= s.size(); ++len)
    for (size_t i = 0, j = len; j <= s.size(); ++i, ++j) {
      if (s[i] == s[j - 1]) f[i][j] = min(f[i][j - 1], f[i + 1][j]);
      for (size_t k = i + 1; k < j; ++k)
        f[i][j] = min(f[i][j], f[i][k] + f[k][j] - (s[k - 1] == s[k]));
    }
  cout << f[0][s.size()];
  return 0;
}