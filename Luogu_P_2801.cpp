#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> struct decompose {
  struct block {
    using vit = typename vector<T>::const_iterator;
    size_t const invl, invr;
    vector<T> data;
    vector<vit> sorted;
    T shift;
    bool unordered;
    template <typename RadnomIterator>
    block(RadnomIterator it, size_t l, size_t r)
        : invl(l),
          invr(r),
          data(it, it + (invr - invl)),
          sorted(data.size()),
          shift(),
          unordered(true) {
      iota(sorted.begin(), sorted.end(), data.begin());
    }
    void invadd(size_t l, size_t r, T x) {
      if (l <= invl && invr <= r) return void(shift += x);
      if (r <= invl || invr <= l) return;
      l = max(l, invl), r = min(r, invr);
      for (size_t i = l; i < r; ++i) data[i - invl] += x;
      unordered = true;
    }
    size_t greater_than_x_count(size_t l, size_t r, T x) {
      x -= shift;
      if (l <= invl && invr <= r) {
        if (unordered)
          unordered = false, sort(sorted.begin(), sorted.end(),
                                  [](vit a, vit b) { return *a < *b; });
        return sorted.end() -
               lower_bound(sorted.cbegin(), sorted.cend(), x,
                           [](vit const& it, T const& x) { return *it < x; });
      }
      if (r <= invl || invr <= l) return 0;
      size_t res = 0;
      l = max(l, invl), r = min(r, invr);
      for (size_t i = l; i < r; ++i) res += data[i - invl] >= x;
      return res;
    }
  };
  size_t const n, blk_count, blk_len;
  block* blk;
  decompose(vector<T> a)
      : n(a.size()),
        blk_count(ceil(sqrt(n))),
        blk_len((n + blk_count - 1) / blk_count),
        blk((block*)(operator new[](sizeof(block) * blk_count))) {
    size_t i = 0;
    for (typename vector<T>::iterator it = a.begin(); i + 1 < blk_count;
         ++i, it += blk_len)
      new (blk + i) block(it, it - a.begin(), it - a.begin() + blk_len);
    new (blk + i) block(a.begin() + i * blk_len, i * blk_len, n);
  }
  void invadd(size_t l, size_t r, T x) {
    size_t ld = l / blk_len, rd = (r + blk_len - 1) / blk_len;
    for (size_t i = ld; i < rd; ++i) blk[i].invadd(l, r, x);
  }
  size_t greater_than_x_count(size_t l, size_t r, T x) {
    size_t ld = l / blk_len, rd = (r + blk_len - 1) / blk_len;
    size_t ans = 0;
    for (size_t i = ld; i < rd; ++i)
      ans += blk[i].greater_than_x_count(l, r, x);
    return ans;
  }
  ~decompose(void) {
    for (size_t i = 0; i < blk_count; ++i) blk[i].~block();
    operator delete[](blk, sizeof(block) * blk_count);
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, q;
  cin >> n >> q;
  vector<li> a(n);
  for (li& i : a) cin >> i;
  decompose<li> b(a);
  while (q--) {
    char op;
    size_t l, r;
    ui x;
    cin >> op >> l >> r >> x;
    --l;
    if (op == 'M')
      b.invadd(l, r, x);
    else
      cout << b.greater_than_x_count(l, r, x) << '\n';
  }
  return 0;
}