#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<vector<bool>> mp(n, vector<bool>(m));
  for (auto &i : mp)
    for (auto j : i) {
      char c;
      cin >> c;
      j = c == '.';
    }
  vector<vector<size_t>> f(n + 1, vector<size_t>(m + 1));
  f[0][1] = 1;
  for (size_t i = 1; i <= n; ++i)
    for (size_t j = 1; j <= m; ++j)
      if (mp[i - 1][j - 1])
        if ((f[i][j] = f[i - 1][j] + f[i][j - 1]) >= 1e9 + 7)
          f[i][j] -= 1e9 + 7;
  cout << f.back().back();
  return 0;
}