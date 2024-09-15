#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using ld = double;
template <typename T> class FenwickTree {
  vector<T> tree;
  T prefix_sum(size_t p) const {
    T res = 0;
    for (--p; p < tree.size(); p = (p & (p + 1)) - 1) res += tree[p];
    return res;
  }

 public:
  FenwickTree(size_t n): tree(n) {}
  void add_point(size_t p, T const& val) {
    for (; p < tree.size(); p |= p + 1) tree[p] += val;
  }
  T get_sum(size_t l, size_t r) const { return prefix_sum(r) - prefix_sum(l); }
  size_t size(void) const { return tree.size(); }
};
template <typename T> class DifferenceFenwick {
  FenwickTree<T> tree;

 public:
  DifferenceFenwick(size_t n): tree(n) {}
  void add_interval(size_t l, size_t r, T const& val) {
    tree.add_point(l, val), tree.add_point(r, -val);
  }
  void add_point(size_t p, T const& val) { add_interval(p, p + 1, val); }
  T get_val(size_t p) const { return tree.get_sum(0, p + 1); }
  size_t size(void) { return tree.size(); }
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
  ui n, l, d;
  cin >> n >> l >> d;
  DifferenceFenwick<ld> f0(n + 1);
  f0.add_point(0, 1);
  for (ui i = 0; i < l; ++i)
    f0.add_interval(i + 1, i + 1 + d, f0.get_val(i) / d);
  vector<ld> p0(n + 1);
  for (size_t i = l; i <= n; ++i) p0[i] = f0.get_val(i);
  PrefixSum<ld> s0(p0.begin(), n + 1);
  FenwickTree<ld> f1(n + d + 1);
  for (ui i = n; i <= n; --i)
    f1.add_point(i, max(f1.get_sum(i + 1, i + 1 + d) / d,
                        1 - s0.get_sum(0, n + 1) + s0.get_sum(0, i)));
  cout << fixed << setprecision(15) << f1.get_sum(0, 1);
  return 0;
}