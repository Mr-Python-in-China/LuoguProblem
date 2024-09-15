#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
struct node {
  ui deepth = 0;
  vector<size_t> next;
};
using graph = vector<node>;
constexpr size_t K = 19;
vector<array<size_t, K>> init(graph& mp, ui root = 0) {
  vector<bool> vis(mp.size());
  vis[root] = true;
  vector<array<size_t, K>> st(mp.size());
  st[root][0] = ~0;
  queue<size_t> q({root});
  while (!q.empty()) {
    ui p = q.front();
    q.pop();
    for (size_t i : mp[p].next)
      if (!vis[i])
        mp[i].deepth = mp[p].deepth + 1, st[i][0] = p, vis[i] = true, q.push(i);
  }
  for (ui k = 1; k < K; k++)
    for (ui i = 0; i < mp.size(); i++)
      st[i][k] = ~st[i][k - 1] ? st[st[i][k - 1]][k - 1] : -1;
  return st;
}
size_t lca(graph const& mp, vector<array<size_t, K>> const& st, size_t x,
           size_t y) {
  if (mp[x].deepth < mp[y].deepth) swap(x, y);
  ui d = mp[x].deepth - mp[y].deepth;
  for (ui k = 0; k < K; ++k)
    if (d & (1 << k)) x = st[x][k];
  if (x == y) return x;
  for (ui k = K - 1; k < K; k--)
    if (st[x][k] != st[y][k]) x = st[x][k], y = st[y][k];
  return st[x][0];
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, s;
  cin >> n >> m >> s;
  --s;
  graph mp(n);
  for (size_t i = 1; i < n; ++i) {
    size_t x, y;
    cin >> x >> y;
    --x, --y;
    mp[x].next.emplace_back(y), mp[y].next.emplace_back(x);
  }
  auto st = init(mp, s);
  while (m--) {
    size_t x, y;
    cin >> x >> y;
    cout << lca(mp, st, --x, --y) + 1 << '\n';
  }
  return 0;
}
