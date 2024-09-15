#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<vector<pair<size_t, ui>>>;
vector<ui> dijkstra(graph const& mp, size_t s) {
  vector<bool> vis(mp.size());
  vector<ui> dis(mp.size(), numeric_limits<ui>::max() / 2);
  dis[s] = 0;
  priority_queue<pair<ui, size_t>, vector<pair<ui, size_t>>,
                 greater<pair<ui, size_t>>>
      q;
  q.emplace(0, s);
  while (!q.empty()) {
    size_t p = q.top().second;
    q.pop();
    if (vis[p]) continue;
    vis[p] = true;
    for (pair<size_t, ui> const& i : mp[p])
      if (dis[p] + i.second < dis[i.first])
        q.emplace(dis[i.first] = dis[p] + i.second, i.first);
  }
  return dis;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, s;
  cin >> n >> m >> s;
  --s;
  graph mp(n);
  while (m--) {
    size_t x, y, z;
    cin >> x >> y >> z;
    mp[--x].emplace_back(--y, z);
  }
  for (ui i : dijkstra(mp, s)) cout << i << ' ';
  return 0;
}