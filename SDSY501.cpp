#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui N = 1e5 + 1;
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
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui x;
  cin >> n >> x;
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  vector<int> d(n + 1);
  for (size_t i = 0; i < n; ++i) d[i + 1] = d[i] + (a[i] < x ? -1 : 1);
  FenwickTree<ui> t(2 * N);
  uli ans = 0;
  for_each(d.rbegin(), d.rend(), [&](int x) {
    ans += t.get_sum(0, 2 * N) - t.get_sum(0, x + N);
    t.add_dot(N + x, 1);
  });
  cout << ans;
  return 0;
}