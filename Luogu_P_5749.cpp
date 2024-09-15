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
  template <typename InputIterator, typename = _RequireInputIter<InputIterator>>
  FenwickTree(InputIterator begin, size_t n): FenwickTree(n) {
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
template <typename T> class DifferenceFenwick {
  FenwickTree<T> tree;

 public:
  DifferenceFenwick(size_t n): tree(n) {}
  void add_interval(size_t l, size_t r, int const& val) {
    tree.add(l, val), tree.add(r, -val);
  }
  void add_point(size_t p, int const& val) { add_interval(p, p + 1, val); }
  int get_val(size_t p) { return tree.get_sum(0, p + 1); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  DifferenceFenwick<size_t> tree(n << 1);
  unordered_map<int, list<size_t>> m;
  vector<int> a(n << 1);
  vector<bool> flag(n << 1);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
    m[a[i]].push_back(i);
  }
  for (size_t i = 0; i < a.size(); ++i) tree.add_point(i, i);
  uli ans = 0;
  for (size_t i = 0; i < a.size(); ++i)
    if (!flag[i]) {
      size_t j = m[-a[i]].front();
      m[a[i]].pop_front(), m[-a[i]].pop_front();
      size_t x = tree.get_val(i), y = tree.get_val(j);
      ans += y - x - 1;
      tree.add_interval(i + 1, j, 1);
      if (a[i] > a[j]) ++ans;
      flag[i] = flag[j] = true;
    }
  cout << ans;
  return 0;
}