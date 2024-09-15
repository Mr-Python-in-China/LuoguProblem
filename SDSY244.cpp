#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<vector<pair<size_t, ui>>>;
vector<ui> bfs(graph const& tree, size_t s) {
  vector<ui> dis(tree.size(), ~0);
  dis[s] = 0;
  queue<size_t> q({s});
  while (!q.empty()) {
    size_t p = q.front();
    q.pop();
    for (pair<size_t, ui> const& i : tree[p])
      if (!~dis[i.first]) dis[i.first] = dis[p] + i.second, q.push(i.first);
  }
  return dis;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui s;
  cin >> n >> s;
  graph mp(n);
  for (size_t i = 1; i < n; ++i) {
    size_t x, y;
    ui z;
    cin >> x >> y >> z;
    --x, --y;
    mp[x].emplace_back(y, z), mp[y].emplace_back(x, z);
  }
  return 0;
}