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
  void add(size_t p, T const& val) {
    for (; p < tree.size(); p |= p + 1) tree[p] += val;
  }
  int get_sum(size_t l, size_t r) { return prefix_sum(r) - prefix_sum(l); }
};
template <typename T> struct decompose {
  struct block {
    using vTi = typename vector<T>::const_iterator;
    size_t invl, invr;
    bool unordered;
    T shift;
    vector<T> data;
    FenwickTree<T> prefixsum;
    vector<vTi> sorted;
    template <typename RandomIterator>
    block(RandomIterator it, size_t l, size_t r)
        : invl(l),
          invr(r),
          unordered(true),
          shift(),
          data(it, it + (r - l)),
          sorted(r - l),
          prefxsum(r - l) {
      iota(sorted.begin(), sorted.end(), data.cbegin());
    }
    void add_if_greater(size_t l, size_t r, T x) {
      if (r <= invl || invr <= l) return;
      if (l <= invl && invr <= r) {
      } else {
        l = max(l, invl), r = min(r, invr);
        for (size_t i = l; i < r; ++i)
          if (data[i - invl] > x) }
    }
  };
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  return 0;
}