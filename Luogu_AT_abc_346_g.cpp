#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> struct decompose {
  struct block {
    size_t invl, invr;
    vector<T> data;
    unordered_map<T, size_t> c;
    T shift;
    template <typename RandomIterator>
    block(RandomIterator it, size_t l, size_t r)
        : invl(l), invr(r), data(it, it + (r - l)), c(), shift() {
      for (T i : data) ++c[i];
    }
    void invadd(size_t l, size_t r, T x) {
      if (l <= invl && invr <= r)
        shift += x;
      else {
        l = max(l, invl), r = min(r, invr);
        for (size_t i = l; i < r; ++i)
          --c[data[i - invl]], ++c[data[i - invl] += x];
      }
    }
    size_t count(size_t l, size_t r, T x) {
      x -= shift;
      if (l <= invl && invr <= r) {
        auto it = c.find(x);
        return it == c.end() ? 0 : it->second;
      } else {
        l = max(l, invl), r = min(r, invr);
        size_t res = 0;
        for (size_t i = l; i < r; ++i) res += data[i] == x;
        return res;
      }
    }
  };
  size_t n, blk_count, blk_len;
  block* blk;
  decompose(vector<T> const& a)
      : n(a.size()),
        blk_count(min<size_t>(sqrt(n), 280)),
        blk_len((n + blk_count - 1) / blk_count),
        blk((block*)(operator new[](sizeof(block) * blk_count))) {
    size_t i = 0;
    typename vector<T>::const_iterator it = a.cbegin();
    for (; i + 1 < blk_count; ++i, it += blk_len)
      new (blk + i) block(it, i * blk_len, (i + 1) * blk_len);
    new (blk + i) block(it, i * blk_len, n);
  }
  void invadd(size_t l, size_t r, T x) {
    size_t ld = l / blk_len, rd = (r + blk_len - 1) / blk_len;
    for (size_t i = ld; i < rd; ++i) blk[i].invadd(l, r, x);
  }
  size_t count(size_t l, size_t r, T x) {
    size_t ld = l / blk_len, rd = (r + blk_len - 1) / blk_len;
    size_t res = 0;
    for (size_t i = ld; i < rd; ++i) res += blk[i].count(l, r, x);
    return res;
  }
  ~decompose(void) {
    for (size_t i = 0; i < blk_count; ++i) blk[i].~block();
    operator delete[](blk, sizeof(block) * blk_count);
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  decompose<int> d((vector<int>(n)));
  vector<vector<size_t>> p(n);
  vector<ui> a(n);
  for (size_t i = 0; i < n; ++i) {
    cin >> a[i], --a[i];
    p[a[i]].push_back(i);
  }
  uli ans = 0;
  for (ui i = 0; i < n; ++i)
    if (!p[i].empty()) d.invadd(p[i][0], p[i].size() > 1 ? p[i][1] : n, 1);
  for (size_t i = 0; i < n; ++i) {
    ans += n - d.count(0, n, 0);
    vector<size_t>::const_iterator it =
        lower_bound(p[a[i]].cbegin(), p[a[i]].cend(), i);
    if (next(it) == p[a[i]].cend())
      d.invadd(*it, n, -1);
    else
      d.invadd(*it, *next(it), -1),
          d.invadd(*next(it), next(it, 2) == p[a[i]].cend() ? n : *next(it, 2),
                   1);
  }
  cout << ans;
  return 0;
}