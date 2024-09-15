#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using node = pair<size_t, ui>;
using graph = vector<vector<node>>;
vector<uli> dijkstra(graph& mp, ui s) {
  vector<uli> dis(mp.size(), numeric_limits<uli>::max() / 2);
  vector<bool> vis(mp.size());
  priority_queue<node, vector<node>, greater<node>> q;
  q.push({0, s});
  dis[s] = 0;
  while (!q.empty()) {
    ui tmp = q.top().second;
    q.pop();
    if (!vis[tmp]) {
      vis[tmp] = true;
      for (vector<pair<size_t, ui>>::reference v : mp[tmp])
        if (dis[v.first] > dis[tmp] + v.second)
          dis[v.first] = dis[tmp] + v.second,
          q.push(node(dis[v.first], v.first));
    }
  }
  return dis;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  graph mp(n);
  for (size_t i = 1; i < n; ++i) {
    ui a, b, x;
    cin >> a >> b >> x;
    --x;
    mp[i - 1].emplace_back(i, a), mp[i - 1].emplace_back(x, b);
  }
  cout << dijkstra(mp, 0).back();
  return 0;
}