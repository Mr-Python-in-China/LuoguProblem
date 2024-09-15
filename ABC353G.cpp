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
        nodel = a.allocate(1), a.construct(nodel, l, l + ((r - l) >> 1), a),
        noder = a.allocate(1), a.construct(noder, l + ((r - l) >> 1), r, a);
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
  void set(size_t p, T val) { root.set(p, val); }
  T query_max(size_t l, size_t r) { return root.query_max(l, r); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  ui c;
  cin >> n >> c >> m;
  SGtree<li> dl(n), dr(n);
  vector<li> f(n);
  for (size_t i = 0; i < n; ++i)
    f[i] = -(c * li(i)), dl.set(i, f[i] - c * uli(i)),
    dr.set(i, f[i] - c * uli(n - i - 1));

  while (m--) {
    size_t t;
    uli p;
    cin >> t >> p;
    --t;
    li x = max({dl.query_max(t + 1, n) + li(t * c),
                dr.query_max(0, t) + li((n - t - 1) * c), f[t]}) +
           p;
    if (x > f[t])
      f[t] = x, dl.set(t, x - t * c), dr.set(t, x - (n - t - 1) * c);
  }
  cout << *max_element(f.begin(), f.end());
  return 0;
}