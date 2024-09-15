#include <iostream>
#include <queue>
#include <set>
using namespace std;
using ui = unsigned int;
using graph = vector<set<ui>>;
void dfs(const graph& mp, ui s = 0) {
  static vector<bool> vis(mp.size(), true);
  vis[s] = false;
  cout << s + 1 << ' ';
  for (set<ui>::const_reference i : mp[s])
    if (vis[i]) dfs(mp, i);
}
void bfs(const graph& mp, ui s = 0) {
  vector<bool> vis(mp.size(), true);
  vis[s] = false;
  queue<ui> q({s});
  while (!q.empty()) {
    ui p = q.front();
    q.pop();
    cout << p + 1 << ' ';
    for (set<ui>::const_reference i : mp[p])
      if (vis[i]) vis[i] = false, q.push(i);
  }
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n, m;
  cin >> n >> m;
  graph mp(n);
  while (m--) {
    ui x, y;
    cin >> x >> y;
    mp[--x].insert(--y);
  }
  dfs(mp);
  cout.put('\n');
  bfs(mp);
  return 0;
}