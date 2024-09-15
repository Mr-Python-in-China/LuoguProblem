#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using uc = unsigned char;
constexpr uli P = 1e9 + 7;
ui quick_2_pow(ui n) {
  static array<ui, size_t(1e5) + 1> mem({});
  if (mem[n]) return mem[n];
  if (n == 0) return mem[n] = 1;
  mem[n] = quick_2_pow(n - 1) * 2;
  if (mem[n] >= P) mem[n] -= P;
  return mem[n];
}
ui mod_plus(ui& a, ui b) {
  a += b;
  if (a >= P) a -= P;
  return a;
}
ui mod_minus(ui& a, ui b) {
  a += P - b;
  if (a >= P) a -= P;
  return a;
}
struct decompose {
  struct block {
    using vTi = typename vector<uc>::const_iterator;
    size_t invl, invr;
    vector<uc> color_t;
    array<uc, 3> t;
    array<ui, 3> cnt;
    vector<ui> clone_cnt;
    array<uc, 3> global_clone_count;
    template <typename RandomIterator>
    block(RandomIterator it, size_t l, size_t r)
        : invl(l),
          invr(r),
          color_t(it, it + (r - l)),
          t({0, 1, 2}),
          cnt({0, 0, 0}),
          clone_cnt(r - l),
          global_clone_count({0, 0, 0}) {
      for (size_t i = 0; i < r - l; ++i) ++cnt[color_t[i]];
    }
    void reset(void) {
      for (size_t i = 0; i < invr - invl; ++i)
        color_t[i] = t[color_t[i]],
        clone_cnt[i] += global_clone_count[color_t[i]];
      global_clone_count = {0, 0, 0};
    }
    void swap_color(size_t l, size_t r, uc c0, uc c1) {
      if (l <= invl && invr <= r) {
        for (uc& i : t)
          if (i == c0)
            i = c1;
          else if (i == c1)
            i = c0;
        swap(cnt[c0], cnt[c1]);
        return;
      }
      if (r <= invl || invr <= l) return;
      reset();
      t = {0, 1, 2};
      l = max(l, invl), r = min(r, invr);
      for (size_t i = l; i < r; ++i)
        if (color_t[i - invl] == c0)
          mod_minus(cnt[c0], quick_2_pow(clone_cnt[i - invl])),
              mod_plus(cnt[c1], quick_2_pow(clone_cnt[i - invl])),
              color_t[i - invl] = c1;
        else if (color_t[i - invl] == c1)
          mod_minus(cnt[c1], quick_2_pow(clone_cnt[i - invl])),
              mod_plus(cnt[c0], quick_2_pow(clone_cnt[i - invl])),
              color_t[i - invl] = c0;
    }
    void set_color(size_t l, size_t r, uc c0, uc c1) {
      if (l <= invl && invr <= r) {
        for (uc& i : t)
          if (i == c0) i = c1;
        mod_plus(cnt[c1], cnt[c0]), cnt[c0] = 0;
        return;
      }
      if (r <= invl || invr <= l) return;
      reset();
      t = {0, 1, 2};
      l = max(l, invl), r = min(r, invr);
      for (size_t i = l; i < r; ++i)
        if (color_t[i - invl] == c0)
          mod_minus(cnt[c0], quick_2_pow(clone_cnt[i - invl])),
              mod_plus(cnt[c1], quick_2_pow(clone_cnt[i - invl])),
              color_t[i - invl] = c1;
    }
    void clone(size_t l, size_t r, uc c) {
      if (l <= invl && invr <= r)
        return ++global_clone_count[c], mod_plus(cnt[c], cnt[c]), void();
      if (r <= invl || invr <= l) return;
      l = max(l, invl), r = min(r, invr);
      for (size_t i = l; i < r; ++i)
        if (t[color_t[i - invl]] == c)
          mod_plus(cnt[c], quick_2_pow(clone_cnt[i - invl]++));
    }
    array<ui, 3> get(size_t l, size_t r) {
      if (l <= invl && invr <= r) return cnt;
      if (r <= invl || invr <= l) return {};
      array<ui, 3> res = {};
      l = max(l, invl), r = min(r, invr);
      for (size_t i = l; i < r; ++i)
        mod_plus(res[t[color_t[i - invl]]], quick_2_pow(clone_cnt[i - invl]));
      return res;
    }
  };
  size_t n, blkcnt, blklen;
  block* blk;
  decompose(vector<uc> const& a)
      : n(a.size()),
        blkcnt(ceil(sqrt(n))),
        blklen((n + blkcnt - 1) / blkcnt),
        blk((block*)operator new[](sizeof(block) * blkcnt)) {
    size_t i = 0;
    typename vector<uc>::const_iterator it = a.cbegin();
    for (; i + 1 < blkcnt; ++i, it += blklen)
      new (blk + i) block(it, i * blklen, (i + 1) * blklen);
    new (blk + i) block(it, i * blklen, n);
  }
  void swap_color(size_t l, size_t r, uc c0, uc c1) {
    size_t lb = l / blklen, rb = (r + blklen - 1) / blklen;
    for (size_t i = lb; i < rb; ++i) blk[i].swap_color(l, r, c0, c1);
  }
  void set_color(size_t l, size_t r, uc c0, uc c1) {
    size_t lb = l / blklen, rb = (r + blklen - 1) / blklen;
    for (size_t i = lb; i < rb; ++i) blk[i].set_color(l, r, c0, c1);
  }
  void clone(size_t l, size_t r, uc c) {
    size_t lb = l / blklen, rb = (r + blklen - 1) / blklen;
    for (size_t i = lb; i < rb; ++i) blk[i].clone(l, r, c);
  }
  array<ui, 3> get(size_t l, size_t r) {
    array<ui, 3> res = {};
    size_t lb = l / blklen, rb = (r + blklen - 1) / blklen;
    for (size_t i = lb; i < rb; ++i) {
      array<ui, 3> tmp = blk[i].get(l, r);
      for (size_t i = 0; i < 3; ++i) mod_plus(res[i], tmp[i]);
    }
    return res;
  }
  ~decompose(void) {
    for (size_t i = 0; i < blkcnt; ++i) blk[i].~block();
    operator delete[](blk);
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<uc> c(n);
  for (uc& i : c) {
    char c;
    cin >> c;
    i = c - '1';
  }
  decompose d(c);
  while (m--) {
    char op;
    cin >> op;
    if (op == '1') {
      size_t l, r;
      char x, y;
      cin >> l >> r >> x >> y;
      d.swap_color(--l, r, x -= '1', y -= '1');
    } else if (op == '2') {
      size_t l, r;
      char x, y;
      cin >> l >> r >> x >> y;
      d.set_color(--l, r, x -= '1', y -= '1');
    } else if (op == '3') {
      size_t l, r;
      char x;
      cin >> l >> r >> x;
      d.clone(--l, r, x -= '1');
    } else
      throw;
    for (ui i : d.get(0, n)) cout << i << ' ';
    cout << '\n';
  }
  return 0;
}