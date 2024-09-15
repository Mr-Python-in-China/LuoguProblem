#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct DSU {
  vector<size_t> fa;
  DSU(size_t n): fa(n) { iota(fa.begin(), fa.end(), size_t(0)); }
  size_t find(size_t x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  bool check(size_t x, size_t y) { return find(x) == find(y); }
  void merge(size_t x, size_t y) { fa[find(x)] = find(y); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<pair<ui, vector<size_t>>> dd;
  while (m--) {
    size_t k;
    ui c;
    cin >> k >> c;
    dd.emplace_back(c, [k] {
      vector<size_t> p(k);
      for (size_t& i : p) cin >> i, --i;
      return p;
    }());
  }
  vector<reference_wrapper<pair<ui, vector<size_t>> const>> d(dd.cbegin(),
                                                              dd.cend());
  sort(d.begin(), d.end(), less<pair<ui, vector<size_t>>>());
  DSU ds(n);
  ui cnt = 0;
  uli ans = 0;
  for (pair<ui, vector<size_t>> const& i : d) {
    for (size_t j : i.second)
      if (!ds.check(i.second.front(), j)) {
        ans += i.first;
        ds.merge(i.second.front(), j);
        if (++cnt >= n - 1) cout << ans, exit(0);
      }
  }
  cout << "-1";
  return 0;
}