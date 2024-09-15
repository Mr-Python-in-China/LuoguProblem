#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n, m;
  cin >> n >> m;
  map<ui, set<ui>> ps;
  vector<pair<ui, ui>> ans;
  vector<ui> sb(n, m);
  for (ui i = 0; i < m; ++i) {
    ui x, y;
    cin >> x >> y;
    --x, --y;
    ps[x].emplace(y);
    --sb[y];
    ans.emplace_back(x, y);
  }
  priority_queue<pair<ui, ui>> q;
  for (ui i = 0; i < n; ++i) q.emplace(sb[i], i);
  for (ui i = 0; i < n; ++i) {
    vector<pair<ui, ui>> tmp;
    set<ui>& s = ps[i];
    while (s.size() != m) {
      pair<ui, ui> t = q.top();
      q.pop();
      if (s.count(t.second))
        tmp.push_back(t);
      else {
        tmp.emplace_back(t.first - 1, t.second);
        s.insert(t.second);
        ans.emplace_back(i, t.second);
      }
    }
    for (auto i : tmp) q.push(i);
  }
  cout << ans.size() << '\n';
  for (auto i : ans) cout << i.first + 1 << ' ' << i.second + 1 << '\n';
  return 0;
}