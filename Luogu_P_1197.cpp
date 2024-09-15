#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<vector<size_t>>;
struct dsds {
  vector<size_t> fa;
  size_t cnt;
  dsds(size_t n): fa(n), cnt(n) { iota(fa.begin(), fa.end(), size_t(0)); }
  size_t find(size_t x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
  bool in_one_set(size_t x, size_t y) { return find(x) == find(y); }
  void merge(size_t x, size_t y) {
    if (!in_one_set(x, y)) --cnt, fa[find(x)] = find(y);
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  graph mp(n);
  while (m--) {
    size_t u, v;
    cin >> u >> v;
    mp[u].emplace_back(v), mp[v].emplace_back(u);
  }
  dsds ds(n);
  size_t k;
  cin >> k;
  vector<size_t> del(k);
  vector<bool> status(n);
  for (size_t& i : del) cin >> i, status[i] = true;
  {
    vector<bool> vis(status);
    queue<size_t> q;
    for (size_t i = 0; i < n; ++i)
      if (!vis[i]) {
        q.push(i), vis[i] = true;
        while (!q.empty()) {
          size_t p = q.front();
          q.pop();
          for (size_t i : mp[p])
            if (!vis[i]) q.push(i), ds.merge(p, i), vis[i] = true;
        }
      }
  }
  size_t t = k;
  vector<size_t> ans;
  for_each(del.crbegin(), del.crend(), [&](size_t p) {
    ans.push_back(ds.cnt - t--);
    status[p] = false;
    for (size_t i : mp[p])
      if (!status[i]) ds.merge(p, i);
  });
  ans.push_back(ds.cnt);
  for_each(ans.crbegin(), ans.crend(), [](size_t p) { cout << p << '\n'; });
  return 0;
}