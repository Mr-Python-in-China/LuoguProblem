#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> struct decompose {
  struct block {
    size_t invl, invr;
    vector<T> data, sorted, sorted_pfs;
    template <typename RandomIterator>
    block(RandomIterator it, size_t l, size_t r,
          allocator<T> alloc = allocator<T>())
        : invl(l),
          invr(r),
          data(it, it + (r - l), alloc),
          sorted(data, alloc),
          sorted_pfs(r - l + 1, alloc) {
      sort(sorted.begin(), sorted.end());
      for (size_t i = 0; i < sorted.size(); ++i)
        sorted_pfs[i + 1] = sorted_pfs[i] + sorted[i];
    }
    size_t le_than_x_sum(size_t l, size_t r, T x) {
      if (l <= invl && invr <= r)
        return sorted_pfs[upper_bound(sorted.cbegin(), sorted.cend(), x) -
                          sorted.cbegin()];
      if (r <= invl || invr <= l) return 0;
      l = max(invl, l), r = min(invr, r);
      size_t res = 0;
      for (size_t i = l; i < r; ++i)
        if (data[i - invl] <= x) res += data[i - invl];
      return res;
    }
  };
  allocator<T> alloc;
  size_t n, blk_count, blk_len;
  block* blk;
  decompose(vector<T> const& a)
      : n(a.size()),
        blk_count(ceil(n / sqrt(n * log2(n)))),
        blk_len((n + blk_count - 1) / blk_count),
        blk((block*)(operator new[](sizeof(block) * blk_count))) {
    size_t i = 0;
    typename vector<T>::const_iterator it = a.cbegin();
    for (; i + 1 < blk_count; ++i, it += blk_len)
      new (blk + i) block(it, i * blk_len, (i + 1) * blk_len, alloc);
    new (blk + i) block(it, i * blk_len, n);
  }
  T le_than_x_sum(size_t l, size_t r, T x) {
    size_t ld = l / blk_len, rd = (r + blk_len - 1) / blk_len;
    size_t res = 0;
    for (size_t i = ld; i < rd; ++i) res += blk[i].le_than_x_sum(l, r, x);
    return res;
  }
  ~decompose(void) {
    for (size_t i = 0; i < blk_count; ++i) blk[i].~block();
    operator delete[](blk, sizeof(block) * blk_count);
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, q;
  cin >> n;
  vector<uli> a(n);
  for (uli& i : a) cin >> i;
  decompose<uli> b(a);
  cin >> q;
  size_t lst = 0;
  while (q--) {
    uli alpha, beta, gamma;
    cin >> alpha >> beta >> gamma;
    size_t l = (alpha ^ lst) - 1, r = beta ^ lst;
    ui x = gamma ^ lst;
    lst = b.le_than_x_sum(l, r, x);
    cout << lst << '\n';
  }
  return 0;
}