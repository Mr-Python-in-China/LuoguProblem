#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<vector<pair<size_t, ui>>>;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  graph mp(n), mpinv(n);
  vector<size_t> outdeg(n);
  while (m--) {
    size_t u, v;
    ui w;
    cin >> u >> v >> w;
    --u, --v;
    mp[u].emplace_back(v, w), mpinv[v].emplace_back(u, w);
    ++outdeg[u];
  }
  vector<size_t> dis(n, ~0);
  vector<size_t> sum(n);
  vector<pair<size_t, ui>> nxt(n);
  queue<size_t> q;
  for (size_t i = 0; i < n; ++i)
    if (outdeg[i] == 0) q.push(i), dis[i] = 0;
  vector<size_t> rank(n);
  auto compare_link = [&nxt, &rank](pair<size_t, ui> x, pair<size_t, ui> y) {
    return x.second != y.second ? x.second < y.second
                                : rank[x.first] < rank[y.first];
  };
  while (!q.empty()) {
    vector<size_t> ndsort;
    for (size_t _ = q.size(); _ > 0; --_) {
      size_t p = q.front();
      q.pop();
      nxt[p] = {~0, numeric_limits<ui>::max()};
      for (pair<size_t, ui> const& i : mp[p])
        if (dis[i.first] + 1 == dis[p] && compare_link(i, nxt[p])) nxt[p] = i;
      if (~nxt[p].first) sum[p] = sum[nxt[p].first] + nxt[p].second;
      ndsort.push_back(p);
      for (pair<size_t, ui> const& i : mpinv[p])
        if (!--outdeg[i.first]) dis[i.first] = dis[p] + 1, q.push(i.first);
    }
    sort(ndsort.begin(), ndsort.end(),
         [&compare_link, &nxt](size_t x, size_t y) {
           return compare_link(nxt[x], nxt[y]);
         });
    for (size_t i = 0; i < ndsort.size(); ++i) rank[ndsort[i]] = i;
  }
  for (size_t i = 0; i < n; ++i) cout << dis[i] << ' ' << sum[i] << '\n';
  return 0;
}