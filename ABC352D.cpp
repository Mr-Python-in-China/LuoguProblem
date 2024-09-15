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
  T const& operator[](size_t p) { return arr[p]; }
  size_t getpos(size_t l, size_t r) {
    size_t k = lg2(r - l) - 1;
    return getcmp(table[k][l], table[k][r - (1 << k)]);
  }
  size_t getval(size_t l, size_t r) { return arr[getpos(l, r)]; }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, k;
  cin >> n >> k;
  vector<size_t> a(n);
  for (size_t& i : a) cin >> i, --i;
  vector<size_t> t(n);
  for (size_t i = 0; i < n; ++i) t[a[i]] = i;
  STtable<size_t, greater<size_t>> x(t.begin(), n);
  STtable<size_t, less<size_t>> y(t.begin(), n);
  size_t ans = numeric_limits<size_t>::max();
  for (size_t i = 0; i < n - k + 1; ++i)
    ans = min(ans, x.getval(i, i + k) - y.getval(i, i + k));
  cout << ans;
  return 0;
}