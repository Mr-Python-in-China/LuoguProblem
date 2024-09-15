// LUOGU_RID: 146128192
#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> class SGtree {
  class node {
    T maxx;
    size_t itvl, itvr;
    node *nodel, *noder;
    bool in_inrerval(size_t l, size_t r) { return l <= itvl && itvr <= r; }
    bool no_matter(size_t l, size_t r) { return r <= itvl || itvr <= l; }

   public:
    node(size_t l, size_t r, allocator<node> a)
        : maxx(), itvl(l), itvr(r), nodel(nullptr), noder(nullptr) {
      if (itvr - itvl > 1) {
        nodel = new node(l, l + ((r - l) >> 1), a),
        noder = new node(l + ((r - l) >> 1), r, a);
      } else
        maxx = T();
    }
    void set(size_t p, T val) {
      if (no_matter(p, p + 1)) return;
      if (in_inrerval(p, p + 1))
        maxx = val;
      else
        nodel->set(p, val), noder->set(p, val),
            maxx = max(nodel->maxx, noder->maxx);
    }
    T query_max(size_t l, size_t r) {
      if (in_inrerval(l, r)) return maxx;
      if (no_matter(l, r)) return numeric_limits<T>::min();
      return max(nodel->query_max(l, r), noder->query_max(l, r));
    }
  } root;

 public:
  SGtree(size_t n, allocator<node> a = allocator<node>()): root(0, n, a) {}
  void add_interval(size_t l, size_t r, T const& v) {
    root.add_interval(l, r, v);
  }
  void set(size_t p, T val) { root.set(p, val); }
  T query_max(size_t l, size_t r) { return root.query_max(l, r); }
};
ui const ABSA = 5e5;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui d;
  cin >> n >> d;
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  SGtree<ui> bt(ABSA + 1);
  vector<ui> f(n);
  for (size_t i = 0; i < n; ++i)
    f[i] = bt.query_max(max<int>(a[i] - d, 0), a[i] + d + 1) + 1,
    bt.set(a[i], f[i]);
  cout << *max_element(f.cbegin(), f.cend());
  return 0;
}