#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
class FenwickTree {
#ifdef debug
 public:
#endif
  vector<int> tree;
  int prefix_sum(size_t p) const {
    int res = 0;
    for (--p; p < tree.size(); p = (p & p + 1) - 1) res += tree[p];
    return res;
  }

 public:
  FenwickTree(size_t n): tree(n) {}
  void add_point(size_t p, int const& val) {
    for (; p < tree.size(); p |= p + 1) tree[p] += val;
  }
  int get_sum(size_t l, size_t r) const {
    return prefix_sum(r) - prefix_sum(l);
  }
  size_t size(void) const { return tree.size(); }
};
class DifferenceFenwick {
#ifdef debug
 public:
#endif
  FenwickTree tree;

 public:
  DifferenceFenwick(size_t n): tree(n) {}
  friend istream& operator>>(istream& in, DifferenceFenwick& t) {
    for (size_t i = 0; i < t.size(); i++) {
      int x;
      in >> x;
      t.add_point(i, x);
    }
#ifdef debug
    cout << "\033[31m";
    for (auto& i : t.tree.tree) cout << i << ' ';
    cout << "\033[0m\n";
#endif
    return in;
  }
  void add_interval(size_t l, size_t r, int const& val) {
    tree.add_point(l, val), tree.add_point(r, -val);
  }
  void add_point(size_t p, int const& val) { add_interval(p, p + 1, val); }
  int get_val(size_t p) { return tree.get_sum(0, p + 1); }
  size_t size(void) { return tree.size(); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<pair<ui, ui>> a(n);
  for (pair<ui, ui>& i : a) {
    cin >> i.first >> i.second;
    if (--i.first > --i.second) swap(i.first, i.second);
  }
  sort(a.begin(), a.end());
  DifferenceFenwick d(n * 2);
  for (pair<ui, ui> i : a) {
    if (d.get_val(i.first) != d.get_val(i.second)) cout << "Yes", exit(0);
    d.add_interval(i.first, i.second, 1);
  }
  cout << "No";
  return 0;
}