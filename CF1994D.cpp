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
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<ui> a(n);
    for (ui &i : a) cin >> i;
    DSU ds(n);
    cout << "YES\n";
    vector<pair<size_t, size_t>> ans;
    for (ui x = n - 1; x >= 1; --x) {
      map<ui, size_t> d;
      for (size_t i = 0; i < n; ++i)
        if (ds.find(i) == i)
          if (d.count(a[i] % x)) {
            ans.emplace_back(d[a[i] % x], i);
            ds.merge(d[a[i] % x], i);
            goto next;
          } else
            d[a[i] % x] = i;
      throw;
    next:;
    }
    for_each(ans.rbegin(), ans.rend(), [](auto const &x) {
      cout << x.first + 1 << ' ' << x.second + 1 << '\n';
    });
  }
  return 0;
}