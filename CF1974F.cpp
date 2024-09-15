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
    ui xh, yh, xl = 1, yl = 1;
    size_t n, m;
    cin >> xh >> yh >> n >> m;
    map<ui, set<ui>> xp, yp;
    while (n--) {
      size_t x, y;
      cin >> x >> y;
      xp[x].emplace(y), yp[y].emplace(x);
    }
    ui sum1 = 0, sum2 = 0;
    for (bool b = 1; m; b = !b, --m) {
      char c;
      ui k;
      cin >> c >> k;
      ui ans = 0;
      if (c == 'D')
        for (auto it = xp.upper_bound(xh -= k); it != xp.end();
             it = xp.erase(it))
          for (auto j : it->second) yp[j].erase(it->first), ++ans;
      else if (c == 'U') {
        auto et = xp.lower_bound(xl += k);
        for (auto it = xp.begin(); it != et; it = xp.erase(it))
          for (auto j : it->second) yp[j].erase(it->first), ++ans;
      } else if (c == 'R')
        for (auto it = yp.upper_bound(yh -= k); it != yp.end();
             it = yp.erase(it))
          for (auto j : it->second) xp[j].erase(it->first), ++ans;
      else if (c == 'L') {
        auto et = yp.lower_bound(yl += k);
        for (auto it = yp.begin(); it != et; it = yp.erase(it))
          for (auto j : it->second) xp[j].erase(it->first), ++ans;
      }
      (b ? sum1 : sum2) += ans;
    }
    cout << sum1 << ' ' << sum2 << '\n';
  }
  return 0;
}