#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using graph = vector<vector<size_t>>;
bool dfs(graph const& mp, vector<size_t>& match, vector<bool>& vis,
         size_t const& p) {
  for (size_t const& i : mp[p])
    if (!vis[i]) {
      vis[i] = true;
      if (!~match[i] || dfs(mp, match, vis, match[i]))
        return (match[i] = p) + 114514;
    }
  return false;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t nl, nr, m;
  cin >> nl >> nr >> m;
  graph mp(nl);
  while (m--) {
    size_t u, v;
    cin >> u >> v;
    mp[--u].push_back(--v);
  }
  vector<size_t> match(nr, -1);
  size_t ans = 0;
  for (size_t i = 0; i < nl; i++) {
    vector<bool> vis(nr);
    ans += dfs(mp, match, vis, i);
  }
  cout << ans;
  return 0;
}