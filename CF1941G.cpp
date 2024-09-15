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
    size_t n, m;
    cin >> n >> m;
    vector<map<ui, vector<size_t>>> sn(n);
    while (m--) {
      size_t a, b;
      ui c;
      cin >> a >> b >> c;
      --a, --b, --c;
      sn[a][c].push_back(b), sn[b][c].push_back(a);
    }
    size_t s, t;
    cin >> s >> t;
    --s, --t;
    deque<pair<size_t, ui>> q({
        {s, ~0}
    });
    vector<map<ui, ui>> dis(n);
    while (!q.empty()) {
      size_t p = q.front().first;
      ui c = q.front().second;
      q.pop_front();
      ui d = dis[p][c];
      if (~c) {
        if (!dis[p].count(~0) || d < dis[p][~0])
          dis[p][~0] = d, q.emplace_front(p, ~0);
        for (size_t i : sn[p][c])
          if (!dis[i].count(c) || d < dis[i][c])
            dis[i][c] = d, q.emplace_front(i, c);
      } else
        for (pair<ui, vector<size_t>> const& i : sn[p])
          if (!dis[p].count(i.first) || d + 1 < dis[p][i.first])
            dis[p][i.first] = d + 1, q.emplace_back(p, i.first);
    }
    cout << dis[t][~0] << '\n';
  }
  return 0;
}