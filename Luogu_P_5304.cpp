#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<vector<pair<size_t, ui>>>;
vector<uli> dijkstra(graph const& mp, size_t s) {
  vector<bool> vis(mp.size());
  vector<uli> dis(mp.size(), numeric_limits<uli>::max() / 2);
  dis[s] = 0;
  priority_queue<pair<uli, size_t>, vector<pair<uli, size_t>>,
                 greater<pair<uli, size_t>>>
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
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, m, k;
    cin >> n >> m >> k;
    graph mp(n);
    while (m--) {
      size_t x, y;
      ui z;
      cin >> x >> y >> z;
      --x, --y;
      mp[x].emplace_back(y, z);
    }
    vector<size_t> t(k);
    for (size_t& i : t) cin >> i, --i;
    uli ans = numeric_limits<uli>::max();
    for (size_t b = 1; b < n; b <<= 1) {
      graph nmp = mp;
      nmp.resize(n + 2);
      for (size_t i : t)
        nmp[n + bool(i & b)].emplace_back(i, 0),
            nmp[i].emplace_back(n + bool(i & b), 0);
      ans = min({ans, dijkstra(nmp, n)[n + 1], dijkstra(nmp, n + 1)[n]});
    }
    cout << ans << '\n';
  }
  return 0;
}