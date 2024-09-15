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
};
uli type1(size_t n, ui d, ui m) {
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  sort(a.begin(), a.end());
  uli ans = 0;
  for (vector<ui>::const_iterator it = a.cbegin(); it < a.cend(); ++it)
    ans += upper_bound(it, a.cend(), *it + d) - 1 - it;
  return ans;
}
uli type2(size_t n, ui d, ui m) {
  struct point {
    ui x, y;
  };
  vector<vector<ui>> am(2 * m + 1);
  for (size_t i = 0; i < n; ++i) {
    point p;
    cin >> p.x >> p.y;
    am[p.x + p.y].push_back(m + p.x - p.y);
  }
  uli ans = 0;
  FenwickTree<uli> t(m * 2 + 1);
  for (ui i = 0; i < am.size(); ++i) {
    for (ui j : am[i])
      ans += t.get_sum(max<int>(0, j - d), min(j + d + 1, m * 2 + 1));
    sort(am[i].begin(), am[i].end());
    for (vector<ui>::const_iterator it = am[i].cbegin(); it < am[i].cend();
         ++it)
      ans += upper_bound(it, am[i].cend(), *it + d) - 1 - it;
    for (ui j : am[i]) t.add(j, 1);
    if (i >= d)
      for (ui j : am[i - d]) t.add(j, -1);
  }
  return ans;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  char b;
  size_t n, m;
  ui d;
  cin >> b >> n >> d >> m;
  cout << (b == '1' ? type1 : b == '2' ? type2 : throw)(n, d, m);
  return 0;
}