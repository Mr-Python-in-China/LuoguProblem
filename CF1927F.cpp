#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<vector<pair<size_t, ui>>>;
struct edge {
  size_t u, v;
  ui w;
};
void tarjan(size_t p, size_t fa, vector<edge>& ans, vector<size_t>& dfn,
            vector<size_t>& low, size_t& t, graph const& mp) {
  low[p] = dfn[p] = t++;
  for (pair<size_t, ui> const& i : mp[p])
    if (!~dfn[i.first]) {
      tarjan(i.first, p, ans, dfn, low, t, mp);
      low[p] = min(low[p], low[i.first]);
      if (low[i.first] <= dfn[p])
        ans.push_back({p, i.first, i.second}),
            ans.push_back({i.first, p, i.second});
    } else {
      if (i.first != fa)
        low[p] = min(low[p], dfn[i.first]),
        ans.push_back({p, i.first, i.second});
    }
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, m;
    cin >> n >> m;
    graph mp(n);
    while (m--) {
      edge i;
      cin >> i.u >> i.v >> i.w;
      --i.u, --i.v;
      mp[i.u].emplace_back(i.v, i.w), mp[i.v].emplace_back(i.u, i.w);
    }
    vector<edge> e;
    vector<size_t> dfn(n, ~0), low(n, ~0);
    size_t t = 0;
    for (size_t i = 0; i < n; ++i)
      if (!~dfn[i]) tarjan(i, ~0, e, dfn, low, t, mp);
    edge mine = e.front();
    for (edge const& i : e)
      if (i.w < mine.w) mine = i;
    graph nmp(n);
    for (edge const& i : e) nmp[i.u].push_back({i.v, i.w});
    vector<size_t> prev(n, ~0);
    queue<size_t> q({mine.u});
    prev[mine.u] = n;
    while (!q.empty()) {
      size_t p = q.front();
      q.pop();
      if (p == mine.v) goto ok;
      for (pair<size_t, ui>& i : nmp[p])
        if (!~prev[i.first] && !(p == mine.u && i.first == mine.v))
          prev[i.first] = p, q.push(i.first);
    }
    throw;
  ok:;
    vector<size_t> ans;
    for (size_t i = mine.v; i != n; i = prev[i]) ans.push_back(i);
    cout << mine.w << ' ' << ans.size() << '\n';
    for (size_t i : ans) cout << i + 1 << ' ';
    cout.put('\n');
  }
  return 0;
}