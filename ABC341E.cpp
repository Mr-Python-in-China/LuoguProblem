#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> class FenwickTree {
  vector<T> tree;
  // To get sum in interval [0,p) (no p).
  T prefix_sum(size_t p) {
    T res = 0;
    for (--p; p < tree.size(); --(p &= (p + 1))) res += tree[p];
    return res;
  }

 public:
  FenwickTree(size_t n): tree(n) {}
  void add(size_t p, T const& val) {
    for (; p < tree.size(); p |= p + 1) tree[p] += val;
  }
  T get_sum(size_t l, size_t r) { return prefix_sum(r) - prefix_sum(l); }
  T get(size_t p) { return get_sum(p, p + 1); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<bool> a(n);
  for (vector<bool>::reference i : a) {
    char c;
    cin >> c;
    i = c == '1';
  }
  FenwickTree<ui> same_as_prev(n);
  for (size_t i = 0; i < n; ++i)
    same_as_prev.add(i, a[i] == (i == 0 ? 0 : a[i - 1]));
  while (m--) {
    char op;
    size_t l, r;
    cin >> op >> l >> r;
    if (op == '1')
      same_as_prev.add(l - 1, same_as_prev.get(l - 1) ? -1 : 1),
          same_as_prev.add(r, same_as_prev.get(r) ? -1 : 1);
    else if (op == '2')
      cout << (same_as_prev.get_sum(l, r) ? "No\n" : "Yes\n");
    else
      throw;
  }
  return 0;
}