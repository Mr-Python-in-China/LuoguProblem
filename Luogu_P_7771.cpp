#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using graph = vector<vector<ui>>;
inline void no(void) {
  cout << "No";
  exit(0);
}
vector<ui> ans;
vector<vector<ui>::const_iterator> vis;
void dfs(const graph& mp, const ui p) {
  for (vector<ui>::const_iterator it = vis[p]; it != mp[p].end(); it = vis[p])
    vis[p] = next(it), dfs(mp, *it);
  ans.push_back(p);
  return;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  graph mp(n);
  vector<int> deg(n);
  while (m--) {
    ui x, y;
    cin >> x >> y;
    mp[--x].push_back(--y);
    deg[x]++, deg[y]--;
  }
  vis.resize(n);
  for (ui i = 0; i < n; i++)
    sort(mp[i].begin(), mp[i].end()), vis[i] = mp[i].cbegin();
  ui start = -1, end = -1;
  for (ui i = 0; i < n; i++)
    if (deg[i] == 1)
      if (~start)
        no();
      else
        start = i;
    else if (deg[i] == -1)
      if (~end)
        no();
      else
        end = i;
    else
      ;
  if (!~start && !~end)
    start = end = 0;
  else if (!~start || !~end)
    no();
  dfs(mp, start);
  for (vector<ui>::const_reverse_iterator it = ans.crbegin(); it != ans.crend();
       it++)
    cout << *it + 1 << ' ';
  return 0;
}