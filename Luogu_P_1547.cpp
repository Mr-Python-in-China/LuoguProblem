#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
struct edge {
  size_t u, v;
  ui w;
  friend bool operator<(edge const& x, edge const& y) { return x.w < y.w; }
};
class dsds {
  vector<size_t> fa;
  size_t find(size_t a) { return fa[a] == a ? a : fa[a] = find(fa[a]); }

 public:
  dsds(size_t n): fa(n) { iota(fa.begin(), fa.end(), 0); }
  void merge(size_t x, size_t y) { fa[find(x)] = find(y); }
  bool in_one_set(size_t x, size_t y) { return find(x) == find(y); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<edge> e(m);
  for (edge& i : e) cin >> i.u >> i.v >> i.w, i.u--, i.v--;
  sort(e.begin(), e.end());
  dsds ds(n);
  size_t cnt = 0;
  for (edge const& i : e)
    if (!ds.in_one_set(i.u, i.v)) {
      ds.merge(i.u, i.v);
      if (++cnt == n - 1) return cout << i.w, 0;
    }
  cout << -1;
  return 0;
}