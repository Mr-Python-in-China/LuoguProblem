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
template <typename T> class PrefixSum {
  vector<T> sum;

 public:
  template <typename InputIterator, typename = _RequireInputIter<InputIterator>>
  PrefixSum(InputIterator begin, size_t n): sum(n + 1) {
    typename vector<T>::iterator it = next(sum.begin());
    *(it++) = *begin;
    for (size_t i = 1; i < n; ++i, ++it) *it = *prev(it) + *++begin;
  }
  T get_sum(size_t m, size_t n) { return sum[n] - sum[m]; }
  T get_val(size_t m) { return get_sum(m, m + 1); }
  T operator[](size_t m) { return get_val(m); }
  size_t size(void) { return sum.size(); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<ui> a(n);
    for (ui& i : a) cin >> i;
    PrefixSum<uli> s(a.begin(), n);
    STtable<ui, less<ui>> stl(a.begin(), n);
    STtable<ui, greater<ui>> stg(a.begin(), n);
    for (size_t i = 0; i < n; ++i) {
      size_t ans = numeric_limits<size_t>::max();
      if (i != 0 && a[i - 1] > a[i]) ans = 1;
      if (i != n - 1 && a[i + 1] > a[i]) ans = 1;
      {
        size_t l = -1, r = i - 1;
        while (l != r) {
          size_t mid = (l + r + 1) >> 1;
          if (s.get_sum(mid, i) > a[i] &&
              stl.getval(mid, i) != stg.getval(mid, i))
            l = mid;
          else
            r = mid - 1;
        }
        if (l != size_t(-1)) ans = min(ans, i - l);
      }
      {
        size_t l = i + 2, r = n + 1;
        while (l != r) {
          size_t mid = (l + r) >> 1;
          if (s.get_sum(i + 1, mid) > a[i] &&
              stl.getval(i + 1, mid) != stg.getval(i + 1, mid))
            r = mid;
          else
            l = mid + 1;
        }
        if (l != n + 1) ans = min(ans, l - i - 1);
      }
      cout << int(ans) << ' ';
    }
    cout << '\n';
  }
  return 0;
}