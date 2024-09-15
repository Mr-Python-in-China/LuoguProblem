#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using uc = unsigned char;
uli P = 998244353;
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
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, k;
  cin >> n >> k;
  vector<uc> a(n);
  iota(a.begin(), a.end(), 0);
  ui ans = 0;
  do {
    FenwickTree<uc> t(n);
    uc s = 0;
    for (uc i : a) s += t.get_sum(i + 1, n), t.add(i, 1);
    if (s == k)
      for (size_t i = 0; i < n; ++i) ans = (ans + (i + 1) * (a[i] + 1)) % P;
  } while (next_permutation(a.begin(), a.end()));
  cout << ans;
  return 0;
}