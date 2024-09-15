#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct dsu {
  vector<size_t> fa;
  size_t find(size_t p) { return p == fa[p] ? p : fa[p] = find(fa[p]); }
  dsu(size_t n): fa(n) { iota(fa.begin(), fa.end(), size_t(0)); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  uli m, p, q;
  cin >> n >> m >> p >> q;
  vector<ui> c(n);
  dsu ds(n + 1);
  for (ui i = m; i > 0; --i) {
    size_t l = (i * p + q) % n, r = (i * q + p) % n + 1;
    for (size_t j = ds.find(l); j < r; j = ds.find(j))
      c[j] = i, ds.fa[j] = j + 1;
  }
  for (ui i : c) cout << i << '\n';
  return 0;
}