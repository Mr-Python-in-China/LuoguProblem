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
    size_t n;
    cin >> n;
    map<pair<ui, ui>, pair<size_t, map<ui, size_t>>> ta, tb, tc;
    auto f = [](map<pair<ui, ui>, pair<size_t, map<ui, size_t>>> const &m,
                pair<ui, ui> k, ui v) -> size_t {
      auto p = m.find(k);
      if (p == m.end()) return 0;
      auto q = p->second.second.find(v);
      if (q == p->second.second.end()) return p->second.first;
      return p->second.first - q->second;
    };
    uli ans = 0;
    ui x, y;
    cin >> x >> y;
    for (size_t i = 2; i < n; ++i) {
      ui z;
      cin >> z;
      ans += f(ta, {x, y}, z), ans += f(tb, {x, z}, y), ans += f(tc, {y, z}, x);
      ++ta[{x, y}].first, ++ta[{x, y}].second[z];
      ++tb[{x, z}].first, ++tb[{x, z}].second[y];
      ++tc[{y, z}].first, ++tc[{y, z}].second[x];
      x = y, y = z;
    }
    cout << ans << '\n';
  }
  return 0;
}