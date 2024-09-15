#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using uli = unsigned long long int;
class FenwickTree {
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
  FenwickTree tree;

 public:
  DifferenceFenwick(size_t n): tree(n) {}
  void add_interval(size_t l, size_t r, int const& val) {
    tree.add_point(l, val), tree.add_point(r, -val);
  }
  void add_point(size_t p, int const& val) { add_interval(p, p + 1, val); }
  int get_val(size_t p) { return tree.get_sum(0, p + 1); }
  size_t size(void) { return tree.size(); }
};
template <typename T> struct STtable {
  vector<vector<T>> stmax;
  function<uli(T)> const& gv;

 public:
  STtable(T begin, size_t n, function<uli(T)> const& f)
      : stmax(ceil(log2(n)), vector<T>(n)), gv(f) {
    iota(stmax[0].begin(), stmax[0].end(), begin);
    for (uli i = 1; i < stmax.size(); i++) {
      uli len = 1 << i;
      for (uli j = 0; j + len <= n; j++)
        stmax[i][j] = gv(stmax[i - 1][j]) > gv(stmax[i - 1][j + (len >> 1)])
                          ? stmax[i - 1][j]
                          : stmax[i - 1][j + (len >> 1)];
    }
  }
  T getmax(size_t l, size_t r) {
    --r;
    size_t k = log2(r - l + 1);
    return gv(stmax[k][l]) > gv(stmax[k][r - (1 << k) + 1])
               ? stmax[k][l]
               : stmax[k][r - (1 << k) + 1];
  }
  T getpoint(size_t p) { return stmax[0][p]; }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, q;
  cin >> n >> q;
  list<uli> lst(n);
  for (uli& i : lst) cin >> i;
  DifferenceFenwick go(n + 1), back(n + 1);
  for (size_t i = 0; i <= n; i++) go.add_point(i, i), back.add_point(i, i);
  vector<list<uli>::iterator> ntit(n + 1);
  iota(ntit.begin(), ntit.end(), lst.begin());
  STtable<size_t> st(0, n, [&ntit](size_t p) { return *ntit[p]; });
  while (q--) {
    size_t pl, pr;
    cin >> pl >> pr;
    size_t l = go.get_val(--pl), r = go.get_val(pr);
    size_t maxp = st.getmax(l, r);
    lst.erase(ntit[l], ntit[maxp]), lst.erase(ntit[maxp + 1], ntit[r]);
    go.add_interval(pl, n + 1, maxp - l),
        go.add_interval(back.get_val(maxp) + 1, n + 1, r - maxp - 1);
    back.add_interval(maxp, n + 1, l - maxp),
        back.add_interval(r, n + 1, r - maxp - 1);
#ifdef debug
    for (size_t i = 0; i <= n; i++) cout << go.get_val(i) << ' ';
    cout << ';';
    for (size_t i = 0; i <= n; i++) cout << back.get_val(i) << ' ';
    cout << endl;
#endif
  }
  for (uli const& i : lst) cout << i;
  return 0;
}