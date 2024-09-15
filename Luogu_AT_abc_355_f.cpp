#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct DSU {
  vector<size_t> fa;
  DSU(size_t n): fa(n) { iota(fa.begin(), fa.end(), size_t(0)); }
  size_t find(size_t p) { return fa[p] == p ? p : fa[p] = find(fa[p]); }
  void merge(size_t x, size_t y) { fa[find(x)] = find(y); }
  bool check(size_t x, size_t y) { return find(x) == find(y); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, q;
  cin >> n >> q;
  array<DSU, 11> s{DSU(n), DSU(n), DSU(n), DSU(n), DSU(n), DSU(n),
                   DSU(n), DSU(n), DSU(n), DSU(n), DSU(n)};
  ui sum = (n - 1) * s.size();
  for (size_t t = 1; t < n; ++t) {
    size_t x, y;
    ui c;
    cin >> x >> y >> c;
    --x, --y;
    for (ui i = c; i < s.size(); ++i)
      if (!s[i].check(x, y)) --sum, s[i].merge(x, y);
  }
  for (size_t t = 0; t < q; ++t) {
    size_t x, y;
    ui c;
    cin >> x >> y >> c;
    --x, --y;
    for (ui i = c; i < s.size(); ++i)
      if (!s[i].check(x, y)) --sum, s[i].merge(x, y);
    cout << sum << '\n';
  }
  return 0;
}