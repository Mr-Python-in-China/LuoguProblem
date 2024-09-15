#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<ui> a(n);
  map<ui, ui> ms;
  {
    set<ui> s;
    vector<ui> t(n);
    for (ui& i : t) cin >> i, s.insert(i);
    size_t i = 0;
    for (ui j : s) ms.emplace(j, i++);
    for (size_t i = 0; i < n; ++i) a[i] = ms[t[i]];
  }
  vector<vector<size_t>> p(ms.size());
  for (size_t i = 0; i < n; ++i) p[a[i]].emplace_back(i);
  vector<bool> state(n, true);
  ui island = 1;
  ui ans = island;
  for (vector<size_t>& i : p) {
    for (size_t j : i) {
      bool l = j == 0 ? false : state[j - 1],
           r = j == n - 1 ? false : state[j + 1];
      if (l && r) ++island;
      if (!l && !r) --island;
      state[j] = false;
    }
    ans = max(ans, island);
  }
  cout << ans;
  return 0;
}