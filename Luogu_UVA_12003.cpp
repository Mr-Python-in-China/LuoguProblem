#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> struct decompose {
  struct block {
    using vTi = typename vector<T>::const_iterator;
    size_t invl, invr;
    vector<T> data;
    vector<vTi> sorted;
    bool unordered;
    template <typename RandomIterator>
    block(RandomIterator it, size_t l, size_t r)
        : invl(l),
          invr(r),
          data(it, it + (r - l)),
          sorted(r - l),
          unordered(true) {
      iota(sorted.begin(), sorted.end(), data.cbegin());
    }
    size_t less_than_x_count(size_t l, size_t r, T const& x) {
      if (l <= invl && invr <= r) {
        if (unordered)
          unordered = false,
          sort(sorted.begin(), sorted.end(),
               [](vTi const& a, vTi const& b) { return *a < *b; });
        return lower_bound(sorted.cbegin(), sorted.cend(), x,
                           [](vTi const& it, T const& x) { return *it < x; }) -
               sorted.begin();
      }
      if (r <= invl || invr <= l) return 0;
      size_t res = 0;
      l = max(l, invl), r = min(r, invr);
      for (size_t i = l; i < r; ++i) res += data[i - invl] < x;
      return res;
    }
    void set(size_t p, T const& x) {
      if (invl <= p && p < invr) unordered = true, data[p - invl] = x;
    }
    T const& get(size_t p) { return data[p - invl]; }
  };
  size_t n, blkcnt, blklen;
  block* blk;
  decompose(vector<T> const& a)
      : n(a.size()),
        blkcnt(ceil(n / sqrt(n * log(n)))),
        blklen((n + blkcnt - 1) / blkcnt),
        blk((block*)operator new[](sizeof(block) * blkcnt)) {
    size_t i = 0;
    typename vector<T>::const_iterator it = a.cbegin();
    for (; i + 1 < blkcnt; ++i, it += blklen)
      new (blk + i) block(it, i * blklen, (i + 1) * blklen);
    new (blk + i) block(it, i * blklen, n);
  }
  size_t less_than_x_count(size_t l, size_t r, T const& x) {
    size_t lb = l / blklen, rb = (r + blklen - 1) / blklen;
    size_t res = 0;
    for (size_t i = lb; i < rb; ++i) res += blk[i].less_than_x_count(l, r, x);
    return res;
  }
  void set(size_t p, T const& x) { blk[p / blklen].set(p, x); }
  T const& get(size_t p) { return blk[p / blklen].get(p); }
  ~decompose(void) {
    for (size_t i = 0; i < blkcnt; ++i) blk[i].~block();
    operator delete[](blk);
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  uli u;
  cin >> n >> m >> u;
  vector<uli> a(n);
  for (uli& i : a) cin >> i;
  decompose<uli> b(a);
  while (m--) {
    size_t l, r, p;
    ui v;
    cin >> l >> r >> v >> p;
    size_t k = b.less_than_x_count(l - 1, r, v);
    b.set(--p, u * k / (r - l + 1));
  }
  for (size_t i = 0; i < n; ++i) cout << b.get(i) << '\n';
  return 0;
}