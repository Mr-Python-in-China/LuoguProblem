#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T, typename cmp = less<T>> class STtable {
  vector<T> arr;
  vector<vector<size_t>> table;
  static size_t lg2(size_t x) { return log2(max<size_t>(--x, 1)) + 1; }
  size_t getcmp(size_t x, size_t y) { return cmp()(arr[x], arr[y]) ? x : y; }

 public:
  template <typename InputIterator, typename = _RequireInputIter<InputIterator>>
  STtable(InputIterator it, size_t n): arr(n), table(lg2(n)) {
    std::copy_n(it, n, arr.begin());
    table.front().resize(n);
    iota(table.front().begin(), table.front().end(), size_t());
    for (size_t i = 1; i < table.size(); i++) {
      size_t k = 1 << i;
      table[i].resize(n - k + 1);
      for (size_t r = k; r <= n; r++)
        table[i][r - k] =
            getcmp(table[i - 1][r - k], table[i - 1][r - (k >> 1)]);
    }
  }
  T const &operator[](size_t p) { return arr[p]; }
  size_t getpos(size_t l, size_t r) {
    size_t k = lg2(r - l) - 1;
    return getcmp(table[k][l], table[k][r - (1 << k)]);
  }
  T const &getval(size_t l, size_t r) { return arr[getpos(l, r)]; }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<ui> s(n);
  for (ui &i : s) cin >> i;
  STtable<ui, greater<ui>> a(s.begin(), n);
  STtable<ui, less<ui>> b(s.begin(), n);
  unordered_map<ui, vector<size_t>> d;
  for (size_t i = 0; i < n; ++i) d[a[i]].emplace_back(i);
  while (m--) {
    size_t l, r;
    cin >> l >> r;
    --l;
    cout << min({[&] { return a.getval(l + 1, r - 1) + a[l] + a[r - 1]; }(),
                 [&] {
                   ui maxv = a.getval(l, r - 2);
                   size_t maxp = *prev(
                       lower_bound(d[maxv].begin(), d[maxv].end(), r - 2));
                   ui rminv = b.getval(maxp + 1, r - 1);
                   size_t rminp = *prev(
                       lower_bound(d[rminv].begin(), d[rminv].end(), r - 1));
                   return min(maxv + rminv + a.getval(rminp, r),
                              maxv + a[r - 2] + a[r - 1]);
                 }(),
                 [&] {
                   ui maxv = a.getval(l + 2, r);
                   size_t maxp =
                       *lower_bound(d[maxv].begin(), d[maxv].end(), l + 2);
                   ui lminv = b.getval(l + 1, maxp);
                   size_t lminp =
                       *lower_bound(d[lminv].begin(), d[lminv].end(), l + 1);
                   return min(maxv + lminv + a.getval(l, lminp),
                              maxv + a[l] + a[l + 1]);
                 }()})
         << '\n';
  }
  return 0;
}