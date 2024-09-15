#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using li = long long int;
template <typename T> struct decompose {
  struct block {
    size_t invl, invr;
    vector<T> data;
    T max1st, max2nd;
    size_t count2nd;
    unordered_map<T, size_t> c;
    template <typename RandomIterator>
    block(RandomIterator it, size_t l, size_t r)
        : invl(l), invr(r), data(it, it + (r - l)) {
      for (T i : data) ++c[i];
      update();
    }
    void update(void) {
      max1st = numeric_limits<T>::min(), max2nd = numeric_limits<T>::min();
      for (T i : data)
        if (i > max1st)
          max2nd = max1st, max1st = i;
        else if (i < max1st && i > max2nd)
          max2nd = i;
      return;
    }
    void set(size_t p, T x) {
      --c[data[p - invl]];
      ++c[data[p - invl] = x];
      update();
    }
    pair<T, T> get_max(size_t l, size_t r) {
      if (l <= invl && invr <= r) { return {max1st, max2nd}; }
      l = max(invl, l), r = min(invr, r);
      pair<T, T> res = {numeric_limits<T>::min(), numeric_limits<T>::min()};
      for (size_t i = l; i < r; ++i)
        if (data[i - invl] > res.first)
          res.second = res.first, res.first = data[i - invl];
        else if (data[i - invl] < res.first && data[i - invl] > res.second)
          res.second = data[i - invl];
      return res;
    }
    size_t count(size_t l, size_t r, T x) {
      if (l <= invl && invr <= r) {
        typename unordered_map<T, size_t>::const_iterator it = c.find(x);
        return it == c.cend() ? 0 : it->second;
      }
      l = max(invl, l), r = min(invr, r);
      size_t cnt = 0;
      for (size_t i = l; i < r; ++i) cnt += data[i - invl] == x;
      return cnt;
    }
  };
  size_t n, blk_count, blk_len;
  block* blk;
  decompose(vector<T> const& a)
      : n(a.size()),
        blk_count(min<size_t>(sqrt(n), 300)),
        blk_len((n + blk_count - 1) / blk_count),
        blk((block*)(operator new[](sizeof(block) * blk_count))) {
    size_t i = 0;
    typename vector<T>::const_iterator it = a.cbegin();
    for (; i + 1 < blk_count; ++i, it += blk_len)
      new (blk + i) block(it, i * blk_len, (i + 1) * blk_len);
    new (blk + i) block(it, i * blk_len, n);
  }
  void set(size_t p, T x) { blk[p / blk_len].set(p, x); }
  pair<T, T> get_max(size_t l, size_t r) {
    size_t ld = l / blk_len, rd = (r + blk_len - 1) / blk_len;
    array<T, 4> s = {numeric_limits<T>::min(), numeric_limits<T>::min()};
    for (size_t i = ld; i < rd; ++i) {
      pair<T, T> t = blk[i].get_max(l, r);
      s[2] = t.first, s[3] = t.second;
      inplace_merge(s.begin(), s.begin() + 2, s.end(), greater<T>());
      typename array<T, 4>::iterator x = unique(s.begin(), s.end());
      if (x - s.begin() == 1) s[1] = numeric_limits<T>::min();
    }
    return {s[0], s[1]};
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
  size_t n, m;
  cin >> n >> m;
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  decompose<ui> ds(a);
  while (m--) {
    char c;
    cin >> c;
    if (c == '1') {
      size_t p;
      ui x;
      cin >> p >> x;
      ds.set(--p, x);
    } else if (c == '2') {
      size_t l, r;
      cin >> l >> r;
      --l;
      cout << ds.count(l, r, ds.get_max(l, r).second) << '\n';
    }
  }

  return 0;
}