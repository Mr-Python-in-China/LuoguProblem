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
  FenwickTree(InputIterator begin, size_t n): tree(n) {
    size_t i = 0;
    while (true) {
      add(i, *begin);
      if (++i >= n) break;
      ++begin;
    }
  }
  void add(size_t p, T const &val) {
    for (; p < tree.size(); p |= p + 1) tree[p] += val;
  }
  T get_sum(size_t l, size_t r) { return prefix_sum(r) - prefix_sum(l); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<pair<ui, ui>> a(n);
  map<ui, size_t> d;
  for (pair<ui, ui> &i : a)
    cin >> i.first >> i.second, d.emplace(i.first, ~0), d.emplace(i.second, ~0);
  {
    size_t j = 0;
    for (auto &i : d) i.second = j++;
  }
  sort(a.begin(), a.end());
  FenwickTree<uli> t(d.size());
  uli ans = 0;
  for (pair<ui, ui> i : a) {
    ans += t.get_sum(d[i.first], d.size());
    t.add(d[i.second], 1);
  }
  cout << ans;
  return 0;
}