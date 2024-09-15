#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct node {
  size_t next, id;
};
void dfs(size_t p, size_t fa, size_t faid, size_t& k, vector<bool>& vis,
         vector<bool>& colored, vector<vector<node>> const& mp,
         vector<size_t>& ans) {
  if (k == 1) {
    cout << "No";
    exit(0);
  }
  if (k == 0) {
    cout << "Yes\n" << ans.size() << '\n';
    for (size_t i : ans) cout << i + 1 << ' ';
    exit(0);
  }
  vis[p] = true;
  for (node i : mp[p])
    if (!vis[i.next]) {
      if (!colored[p]) {
        ans.push_back(i.id);
        if (!colored[i.next]) k -= 2;
        colored[p] = colored[i.next] = true;
      }
      dfs(i.next, p, i.id, k, vis, colored, mp, ans);
    }
  if (!colored[p] && ~fa) {
    ans.push_back(faid);
    colored[fa] = false;
  }
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, k;
  cin >> n >> m >> k;
  vector<vector<node>> mp(n);
  for (size_t i = 0; i < m; ++i) {
    size_t a, b;
    cin >> a >> b;
    --a, --b;
    mp[a].push_back({b, i}), mp[b].push_back({a, i});
  }
  vector<bool> vis(n), colored(n);
  vector<size_t> ans;
  for (size_t i = 0; i < n; ++i)
    if (!vis[i]) dfs(i, ~0, ~0, k, vis, colored, mp, ans);
  cout << "No";
  return 0;
}