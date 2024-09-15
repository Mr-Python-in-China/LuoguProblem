#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
bool dfs(vector<vector<size_t>> const& mp, vector<size_t>& match,
         vector<bool>& vis, size_t p) {
  for (size_t const& i : mp[p])
    if (!vis[i]) {
      vis[i] = true;
      if (!~match[i] || dfs(mp, match, vis, match[i])) {
        match[i] = p;
        return true;
      }
    }
  return false;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, e;
  cin >> n >> m >> e;
  vector<vector<size_t>> mp(n);
  while (e--) {
    size_t x, y;
    cin >> x >> y;
    mp[--x].push_back(--y);
  }
  size_t ans = 0;
  vector<size_t> match(m, -1);
  for (size_t i = 0; i < n; i++) {
    vector<bool> vis(m);
    ans += dfs(mp, match, vis, i);
  }
  cout << ans;
  return 0;
}