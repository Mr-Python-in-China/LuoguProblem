#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr size_t T = 1e6 + 2;
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
  cin >> n;
  static bitset<T> xvis, yvis;
  static array<map<size_t, ui>, T> q;
  static array<set<size_t>, T> d;
  for (size_t i = 0; i < n; ++i) {
    size_t x, y;
    cin >> x >> y;
    d[x].insert(y);
    xvis[x] = yvis[y] = true;
    q[x + 1].insert({
        {y + 1, 0},
        {T - 1, 0}
    }),
        q[T - 1].insert({{y + 1, 0}, {T - 1, 0}}),
        q[x].insert({{y + 1, 0}, {T - 1, 0}}),
        q[T - 1].insert({{y + 1, 0}, {T - 1, 0}}),
        q[x + 1].insert({{y, 0}, {T - 1, 0}}),
        q[T - 1].insert({{y, 0}, {T - 1, 0}}),
        q[x].insert({{y, 0}, {T - 1, 0}}),
        q[T - 1].insert({{y, 0}, {T - 1, 0}});
  }
  FenwickTree<ui> t(T);
  for (size_t i = 0; i < T; ++i) {
    for (pair<size_t const, ui>& j : q[i]) j.second = t.get_sum(0, j.first);
    for (size_t j : d[i]) t.add_dot(j, 1);
  }
  ui ans = numeric_limits<ui>::max();
  for (size_t i = 0; i < T; ++i)
    for (size_t j : d[i]) {
      // if (xvis[i+1]||yvis[j+1]) continue;
      ui a1 = q[i][j], a2 = q[i][T - 1] - a1, a3 = q[T - 1][j] - a1,
         a4 = q[T - 1][T - 1] - a1 - a2 - a3, b1 = q[i + 1][j + 1],
         b2 = q[i + 1][T - 1] - b1, b3 = q[T - 1][j + 1] - b1,
         b4 = q[T - 1][T - 1] - b1 - b2 - b3, c1 = q[i + 1][j],
         c2 = q[i + 1][T - 1] - c1, c3 = q[T - 1][j] - c1,
         c4 = q[T - 1][T - 1] - c1 - c2 - c3, d1 = q[i][j + 1],
         d2 = q[i][T - 1] - d1, d3 = q[T - 1][j + 1] - d1,
         d4 = q[T - 1][T - 1] - d1 - d2 - d3;
      ans = min({ans, max({a1, a2, a3, a4}), max({b1, b2, b3, b4}),
                 max({c1, c2, c3, c4}), max({d1, d2, d3, d4})});
    }
  cout << ans;
  return 0;
}