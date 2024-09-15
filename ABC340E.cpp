#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> class FenwickTree {
  vector<T> tree;
  T prefix_sum(size_t p) const {
    T res = 0;
    for (--p; p < tree.size(); p = (p & (p + 1)) - 1) res += tree[p];
    return res;
  }

 public:
  FenwickTree(size_t n): tree(n) {}
  void add_dot(size_t p, T const& val) {
    for (; p < tree.size(); p |= p + 1) tree[p] += val;
  }
  T get_sum(size_t l, size_t r) const { return prefix_sum(r) - prefix_sum(l); }
  size_t size(void) const { return tree.size(); }
};
template <typename T> class DifferenceFenwick {
  FenwickTree<T> tree;

 public:
  DifferenceFenwick(size_t n): tree(n) {}
  friend istream& operator>>(istream& in, DifferenceFenwick& t) {
    for (size_t i = 0; i < t.size(); i++) {
      T x;
      in >> x;
      t.add_poT(i, x);
    }
    return in;
  }
  void add_interval(size_t l, size_t r, T const& val) {
    tree.add_dot(l, val), tree.add_dot(r, -val);
  }
  void add_point(size_t p, T const& val) { add_interval(p, p + 1, val); }
  T get_val(size_t p) { return tree.get_sum(0, p + 1); }
  size_t size(void) { return tree.size(); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  DifferenceFenwick<li> a(n);
  for (size_t i = 0; i < n; ++i) {
    ui x;
    cin >> x;
    a.add_point(i, x);
  }
  while (m--) {
    size_t p;
    cin >> p;
    uli x = a.get_val(p);
    a.add_point(p, -x);
    a.add_interval(0, n, x / n);
    x %= n;
    if (p + x >= n)
      a.add_interval(p + 1, n, 1), a.add_interval(0, x - (n - (p + 1)), 1);
    else
      a.add_interval(p + 1, p + x + 1, 1);
  }
  for (size_t i = 0; i < n; ++i) cout << a.get_val(i) << ' ';
  return 0;
}