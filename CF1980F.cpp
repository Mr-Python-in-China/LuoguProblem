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
    ui n, m;
    size_t k;
    cin >> n >> m >> k;
    vector<pair<ui, ui>> ps(k);
    map<ui, set<ui>> py;
    for (size_t i = 0; i < k; ++i) {
      ui x, y;
      cin >> x >> y;
      ps[i] = {x, y};
      py[y].insert(x);
    }
    set<pair<ui, ui>> keypoint;
    ui x = 0, y = 0;
    auto pyt = py.begin();
    uli ans = 0;
    while (pyt != py.end()) {
      while (pyt != py.end() && *pyt->second.rbegin() < x) ++pyt;
      ui ny = (pyt == py.end() ? n + 1 : pyt->first - 1),
         nx = (pyt == py.end() ? m + 1 : *pyt->second.rbegin() + 1);
      keypoint.emplace(nx - 1, ny + 1);
      ans += uli(nx - x) * (ny + 1);
      x = nx, y = ny;
    }
    cout << ans << '\n';
    for (auto i : ps) cout << keypoint.count(i) << ' ';
    cout << '\n';
  }
  return 0;
}