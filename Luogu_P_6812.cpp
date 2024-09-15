#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> class Difference {
 public:
  vector<T> d;
  template <typename InputIterator, typename = _RequireInputIter<InputIterator>>
  Difference(InputIterator begin, size_t n): d(n) {
    InputIterator lst(begin++);
    typename vector<T>::iterator it = d.begin();
    *(it++) = *lst;
    while (true) {
      *it = *begin - *lst;
      if (++it >= d.end()) break;
      lst = begin++;
    }
  }
  void add_interval(size_t l, size_t r, T val) {
    d[l] += val;
    if (r < d.size()) d[r] -= val;
  }
  template <typename OutputIterator> void get_arr(OutputIterator output) {
    typename vector<T>::iterator it = d.begin();
    while (true) {
      *output = *it;
      if (++it >= d.end()) break;
      ++output;
    }
  }
};
struct SGtree {
  struct node {
    li val;
    node *nodel, *noder;
    size_t itvl, itvr;
    bool in_interval(size_t l, size_t r) { return l <= itvl && itvr <= r; }
    bool no_matter(size_t l, size_t r) { return r <= itvl || itvr <= l; }
    template <typename InputIterator,
              typename = _RequireInputIter<InputIterator>>
    node(InputIterator& it, size_t ql, size_t qr): itvl(ql), itvr(qr) {
      if (itvr - itvl == 1)
        val = *(it++);
      else {
        size_t mid = ((itvr - itvl) >> 1) + itvl;
        nodel = new node(it, itvl, mid), noder = new node(it, mid, itvr);
        val = min(nodel->val, noder->val);
      }
    }
    void add_point(size_t p, li v) {
      if (no_matter(p, p + 1)) return;
      if (itvr - itvl == 1)
        val += v;
      else {
        nodel->add_point(p, v), noder->add_point(p, v);
        val = min(nodel->val, noder->val);
      }
    }
    li query(size_t l, size_t r) {
      if (no_matter(l, r)) return numeric_limits<li>::max();
      if (in_interval(l, r)) return val;
      return min(nodel->query(l, r), noder->query(l, r));
    }
  } root;
  template <typename InputIterator, typename = _RequireInputIter<InputIterator>>
  SGtree(InputIterator it, size_t n): root(it, 0, n){};
  void add_point(size_t p, li x) { root.add_point(p, x); }
  li query(size_t l, size_t r) { return root.query(l, r); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, k;
  cin >> n >> k;
  SGtree tree(Difference<li>(istream_iterator<li>(cin), n).d.cbegin(), n);
  while (k--) {
    char opt;
    size_t l, r;
    cin >> opt >> l >> r;
    if (r == n + 1) r = n;
    --l;
    if (opt == '1') {
      li x;
      cin >> x;
      tree.add_point(l, x), tree.add_point(r, -x);
    } else
      cout << (tree.query(l + 1, r) >= 0 ? "Yes\n" : "No\n");
  }
  return 0;
}