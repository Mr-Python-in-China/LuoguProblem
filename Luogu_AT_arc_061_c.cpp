#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<map<ui, vector<size_t>>> mp(n);
  while (m--) {
    size_t x, y;
    ui z;
    cin >> x >> y >> z;
    --x, --y;
    mp[x][z].push_back(y), mp[y][z].push_back(x);
  }
  deque<pair<size_t, ui>> q({
      {0, ~0}
  });
  vector<map<ui, ui>> dis(n);
  dis[0][~0] = 0;
  while (!q.empty()) {
    size_t p = q.front().first;
    ui c = q.front().second;
    q.pop_front();
    ui d = dis[p][c];
    if (~c) {
      if (!dis[p].count(~0) || dis[p][~0] > d + 1)
        dis[p][~0] = d + 1, q.emplace_back(p, ~0);
      for (size_t i : mp[p][c])
        if (!dis[i].count(c) || dis[i][c] > d)
          dis[i][c] = d, q.emplace_front(i, c);
    } else
      for (pair<ui, vector<size_t>> const& i : mp[p])
        if (!dis[p].count(i.first) || d < dis[p][i.first])
          dis[p][i.first] = d, q.emplace_front(p, i.first);
  }
  dis[n - 1].count(~0) ? cout << dis[n - 1][~0] : cout << "-1";
  return 0;
}