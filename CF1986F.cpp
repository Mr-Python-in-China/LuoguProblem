#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<set<size_t>>;
struct edge {
  size_t u, v;
};
void tarjan(size_t p, size_t fa, vector<edge> &ans, vector<size_t> &dfn,
            vector<size_t> &low, size_t &t, graph const &mp) {
  low[p] = dfn[p] = t++;
  for (size_t const &i : mp[p])
    if (!~dfn[i]) {
      tarjan(i, p, ans, dfn, low, t, mp);
      low[p] = min(low[p], low[i]);
      if (low[i] > dfn[p]) ans.push_back({p, i}), ans.push_back({i, p});
    } else {
      if (i != fa) low[p] = min(low[p], dfn[i]);
    }
}
void f(graph const &mp, vector<size_t> const &v, vector<size_t> &fas,
       vector<size_t> &sz, size_t p, size_t fa = ~0) {
  fas[p] = fa;
  sz[p] = v[p];
  for (size_t i : mp[p])
    if (i != fa) {
      f(mp, v, fas, sz, i, p);
      sz[p] += sz[i];
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
      size_t x, y;
      cin >> x >> y;
      --x, --y;
      mp[x].emplace(y), mp[y].emplace(x);
    }
    vector<edge> e;
    vector<size_t> dfn(n, ~0), low(n, ~0);
    size_t t = 0;
    for (size_t i = 0; i < n; ++i)
      if (!~dfn[i]) tarjan(i, ~0, e, dfn, low, t, mp);
    graph nmp = mp;
    for (edge const &i : e) nmp[i.u].erase(i.v);
    size_t d = 0;
    vector<size_t> color(n, ~0);
    for (size_t i = 0; i < n; ++i)
      if (!~color[i]) {
        queue<size_t> q({i});
        color[i] = d;
        while (!q.empty()) {
          size_t p = q.front();
          q.pop();
          for (size_t np : nmp[p])
            if (!~color[np]) color[np] = d, q.emplace(np);
        }
        ++d;
      }
    graph tree(d);
    for (edge const &i : e) tree[color[i.u]].emplace(color[i.v]);
    vector<size_t> cnt(d);
    for (size_t i : color) ++cnt[i];
    vector<size_t> fa(d, ~0), sz(d);
    f(tree, cnt, fa, sz, 0);
    uli ans = n * uli(n - 1) / 2;
    for (size_t i = 1; i < d; ++i)
      ans = min<uli>(ans, sz[i] * uli(sz[i] - 1) / 2 +
                              ((sz[0] - sz[i]) * uli(sz[0] - sz[i] - 1)) / 2);
    cout << ans << '\n';
  }
  return 0;
}