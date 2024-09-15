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
        return match[i] = p, true;
    }
  return false;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  graph mp(n);
  for (vector<size_t>& i : mp) {
    size_t s;
    cin >> s;
    i.resize(s);
    for (size_t& j : i) cin >> j, --j;
  }
  vector<size_t> match(n, -1);
  size_t ans = 0;
  for (size_t i = 0; i < n; i++) {
    vector<bool> vis(n);
    ans += dfs(mp, match, vis, i);
  }
  cout << ans;
  return 0;
}