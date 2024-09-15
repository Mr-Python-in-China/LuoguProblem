#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using uc = unsigned char;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    array<array<bool, 7>, 7> mp;
    for (array<bool, 7>& i : mp)
      for (bool& j : i) {
        char c;
        cin >> c;
        j = c == 'B';
      }
    array<array<set<pair<uc, uc>>, 7>, 7> f = {};
    for (uc i = 1; i < 6; ++i)
      for (uc j = 1; j < 6; ++j)
        if (mp[i][j] && mp[i - 1][j - 1] && mp[i - 1][j + 1] &&
            mp[i + 1][j - 1] && mp[i + 1][j + 1])
          f[i][j].insert({i, j}), f[i - 1][j - 1].insert({i, j}),
              f[i + 1][j - 1].insert({i, j}), f[i - 1][j + 1].insert({i, j}),
              f[i + 1][j + 1].insert({i, j});
    size_t ans = 0;
    auto rm = [&f](uc x, uc y, pair<uc, uc> target) {
      if (x < 7 && y < 7) f[x][y].erase(target);
    };
    while (true) {
      pair<uc, uc> p(0, 0);
      for (uc i = 0; i < 7; ++i)
        for (uc j = 0; j < 7; ++j)
          if (f[i][j].size() > f[p.first][p.second].size()) p = {i, j};
      if (f[p.first][p.second].empty()) break;
      set<pair<uc, uc>> cp = f[p.first][p.second];
      for (pair<uc, uc> j : cp)
        rm(j.first, j.second, j), rm(j.first - 1, j.second - 1, j),
            rm(j.first - 1, j.second + 1, j), rm(j.first + 1, j.second - 1, j),
            rm(j.first + 1, j.second + 1, j);
      ++ans;
    }
    cout << ans << '\n';
  }
  return 0;
}