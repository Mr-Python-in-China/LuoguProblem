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
  template <typename InputIterator, typename = _RequireInputIter<InputIterator>>
  FenwickTree(InputIterator begin, size_t n): tree(n) {
    size_t i = 0;
    while (true) {
      add(i, *begin);
      if (++i >= n) break;
      ++begin;
    }
  }
  FenwickTree(size_t n): tree(n) {}
  void add(size_t p, T const &val) {
    for (; p < tree.size(); p |= p + 1) tree[p] += val;
  }
  T get_sum(size_t l, size_t r) { return prefix_sum(r) - prefix_sum(l); }
  size_t lower_bound(T s) {
    if (tree.size() == 1) return 0;
    unsigned char k = ceil(log2(tree.size()));
    T sum = get_sum(0, tree.size());
    size_t p = 0;
    for (; k; --k) {
      size_t lp = p | (1 << (k - 1));
      T d = lp > tree.size() ? sum : tree[lp - 1];
      if (s <= d)
        ;
      else
        s -= d, p = lp;
    }
    return p;
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    FenwickTree<size_t> a(vector<size_t>(n, 1).begin(), n);
    size_t p = 0;
    for (size_t i = 0; i < n - 1; ++i) {
      p = (p + i) % (n - i);
      a.add(a.lower_bound(p + 1), -1);
      if (p == n - i - 1) p = 0;
    }
    cout << a.lower_bound(p + 1) + 1 << '\n';
  }
  return 0;
}