#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, x, y;
  cin >> n >> m >> x >> y;
  --x, --y;
  vector<vector<bool>> mp(n, vector<bool>(m));
  for (vector<bool> &i : mp)
    for (vector<bool>::reference j : i) {
      char c;
      cin >> c;
      j = c == '.';
    }
  string s;
  cin >> s;
  for (char i : s) {
    if (i == 'U')
      if (x - 1 < n && mp[x - 1][y]) --x;
    if (i == 'D')
      if (x + 1 < n && mp[x + 1][y]) ++x;
    if (i == 'L')
      if (y - 1 < m && mp[x][y - 1]) --y;
    if (i == 'R')
      if (y + 1 < m && mp[x][y + 1]) ++y;
  }
  cout << x + 1 << ' ' << y + 1;
  return 0;
}