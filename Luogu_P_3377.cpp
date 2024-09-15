#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct DSDS {
  vector<size_t> fa;
  DSDS(size_t n): fa(n) { iota(fa.begin(), fa.end(), 0); }
  size_t find(size_t x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  size_t find(size_t x) const { return fa[x] == x ? x : find(fa[x]); }
  bool in_one_set(size_t x, size_t y) { return find(x) == find(y); }
  bool in_one_set(size_t x, size_t y) const { return find(x) == find(y); }
  void merge(size_t x, size_t y) { fa[find(x)] = find(y); }
};
int main(void) {
#ifndef debug
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#endif
  size_t n, m;
  cin >> n >> m;
  DSDS ds(n);
  vector<pbds::priority_queue<pair<int, size_t>, greater<pair<int, size_t>>>>
      pqs(n);
  vector<bool> del(n);
  for (size_t i = 0; i < n; ++i) {
    int x;
    cin >> x;
    pqs[i].push({x, i});
  }
  while (m--) {
    char op;
    cin >> op;
    if (op == '1') {
      size_t x, y;
      cin >> x >> y;
      --x, --y;
      if (!del[x] && !del[y] && !ds.in_one_set(x, y))
        pqs[ds.find(x)].join(pqs[ds.find(y)]), ds.merge(y, x);
    } else {
      size_t x;
      cin >> x;
      --x;
      if (del[x] || pqs[ds.find(x)].empty())
        cout << "-1\n";
      else {
        size_t tmp = ds.find(x);
        cout << pqs[tmp].top().first << '\n', del[pqs[tmp].top().second] = true,
                                              pqs[tmp].pop();
      }
    }
  }
  return 0;
}
