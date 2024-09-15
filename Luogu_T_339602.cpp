#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
constexpr size_t N = 1e6 + 1;
array<set<size_t>, N> bottle;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  bool c1, c2;
  cin >> n >> m >> c1 >> c2;
  vector<ui> s(n);
  for (size_t i = 0; i < n; i++) cin >> s[i], bottle[s[i]].insert(i);
  vector<ui> t;
  t.reserve(m);
  for (size_t i = 0; i < m; i++) {
    ui x;
    cin >> x;
    if (!bottle[x].empty()) t.push_back(x);
  }
  size_t lstpos = *bottle[t.front()].begin(), p = 1;
  for (size_t i = 1; i < t.size(); i++) {
    set<size_t>::iterator nowpos = bottle[t[i]].upper_bound(lstpos);
    if (nowpos == bottle[t[i]].end()) nowpos = bottle[t[i]].begin(), p++;
    lstpos = *nowpos;
  }
  cout << t.size() * c1 << ' ' << p * c2;
  return 0;
}