#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<vector<tuple<size_t, ui, bool>>>;
void get_subtree(graph const& mp, size_t p, size_t fa,
                 vector<ui>& subtree_ans) {
  for (tuple<size_t, ui, bool> const& i : mp[p])
    if (get<0>(i) != fa)
      get_subtree(mp, get<0>(i), p, subtree_ans),
          subtree_ans[p] +=
          subtree_ans[get<0>(i)] + (get<0>(i) < p) ^ get<2>(i);
}
void change_root(graph const& mp, size_t p, size_t fa,
                 vector<ui> const& subtree_ans, vector<ui>& root_ans) {
  for (tuple<size_t, ui, bool> const& i : mp[p])
    if (get<0>(i) != fa)
      root_ans[get<0>(i)] =
          root_ans[p] + ((get<0>(i) < p) ^ get<2>(i) ? -1 : 1),
      change_root(mp, get<0>(i), p, subtree_ans, root_ans);
}
vector<ui> bfs(graph const& mp, size_t root) {
  vector<ui> dis(mp.size(), -1);
  dis[root] = 0;
  queue<size_t> q({root});
  while (!q.empty()) {
    size_t p = q.front();
    q.pop();
    for (tuple<size_t, ui, bool> const& i : mp[p])
      if (dis[get<0>(i)] == -1)
        dis[get<0>(i)] = dis[p] + get<1>(i), q.push(get<0>(i));
  }
  return dis;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui d;
  cin >> n >> d;
  graph mp(n);
  for (size_t i = 1; i < n; ++i) {
    size_t u, v;
    ui w;
    cin >> u >> v >> w;
    --u, --v;
    mp[u].push_back({v, w, u < v}), mp[v].push_back({u, w, u < v});
  }
  vector<ui> subtree_ans(n);
  get_subtree(mp, 0, -1, subtree_ans);
  vector<ui> root_ans(n);
  root_ans[0] = subtree_ans[0];
  change_root(mp, 0, -1, subtree_ans, root_ans);
  size_t d1 = 0, d2 = 0;
  {
    vector<ui> tmp_dis(bfs(mp, 0));
    for (size_t i = 0; i < n; ++i)
      if (tmp_dis[i] > tmp_dis[d1]) d1 = i;
  }
  vector<ui> dis1(bfs(mp, d1));
  for (size_t i = 0; i < n; ++i)
    if (dis1[i] > dis1[d2]) d2 = i;
  vector<ui> dis2(bfs(mp, d2));
  ui ans = -1;
  for (size_t i = 0; i < n; ++i)
    if (max(dis1[i], dis2[i]) <= d) ans = min(ans, root_ans[i]);
  cout << int(ans);
  return 0;
}