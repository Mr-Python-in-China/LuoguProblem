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
  void add(size_t p, T const& val) {
    for (; p < tree.size(); p |= p + 1) tree[p] += val;
  }
  T get_sum(size_t l, size_t r) { return prefix_sum(r) - prefix_sum(l); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  unordered_map<ui, size_t> mapper;
  {
    vector<ui> b(a);
    sort(b.begin(), b.end());
    for (size_t i = 0; i < n; ++i) mapper[b[i]] = i;
  }
  FenwickTree<uli> fcnt(n), fsum(n);
  uli ans = 0;
  for (size_t i = 0; i < n; ++i) {
    size_t p = mapper[a[i]];
    ans += fcnt.get_sum(0, p) * __uint128_t(a[i]) - fsum.get_sum(0, p);
    fcnt.add(p, 1), fsum.add(p, a[i]);
  }
  cout << ans;
  return 0;
}