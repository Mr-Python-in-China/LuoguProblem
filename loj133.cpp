#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> struct FenwickTree {
  vector<T> tree;
  FenwickTree(size_t n, T const& x): tree(n, x) {}
  FenwickTree(size_t n): tree(n) {}
  // To get sum in interval [0,p) (no p).
  template <typename F> void foreach_p(size_t p, F const& f) {
    for (--p; p < tree.size(); --(p &= (p + 1))) f(tree[p]);
  }
  template <typename F> void foreach_n(size_t p, F const& f) {
    for (; p < tree.size(); p |= p + 1) f(tree[p]);
  }
  T prefix_sum(size_t p) {
    T res = T();
    foreach_p(p, [&res](T const& x) { res += x; });
    return res;
  }
  void add(size_t p, T const& val) {
    foreach_n(p, [&val](T& x) { x += val; });
  }
  T get_sum(size_t l, size_t r) { return prefix_sum(r) - prefix_sum(l); }
};
template <typename T> struct FenwickTree2d {
  FenwickTree<FenwickTree<T>> t;
  FenwickTree2d(size_t n, size_t m): t(n, FenwickTree<T>(m)) {}
  void add(size_t x, size_t y, T const& val) {
    t.foreach_n(x, [y, &val](FenwickTree<T>& d) { d.add(y, val); });
  }
  T prefix_sum(size_t x, size_t y) {
    T res = 0;
    t.foreach_p(x, [y, &res](FenwickTree<T>& d) { res += d.prefix_sum(y); });
    return res;
  }
  T get_sum(size_t x1, size_t y1, size_t x2, size_t y2) {
    return prefix_sum(x2, y2) + prefix_sum(x1, y1) - prefix_sum(x1, y2) -
           prefix_sum(x2, y1);
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  FenwickTree2d<li> s(n, m);
  for (char t; cin >> t;)
    if (t == '1') {
      size_t x, y;
      li k;
      cin >> x >> y >> k;
      s.add(--x, --y, k);
    } else if (t == '2') {
      size_t a, b, c, d;
      cin >> a >> b >> c >> d;
      cout << s.get_sum(--a, --b, c, d) << '\n';
    }
  return 0;
}