#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 1e9 + 7;
template <int m, std::enable_if_t<(1 <= m)> * = nullptr> struct static_modint {
  using mint = static_modint;

 public:
  static constexpr int mod() { return m; }
  static mint raw(int v) {
    mint x;
    x._v = v;
    return x;
  }

  static_modint(): _v(0) {}
  template <class T, typename = is_unsigned<T>> static_modint(T v) {
    _v = (unsigned int)(v % umod());
  }

  unsigned int val() const { return _v; }

  mint &operator++() {
    _v++;
    if (_v == umod()) _v = 0;
    return *this;
  }
  mint &operator--() {
    if (_v == 0) _v = umod();
    _v--;
    return *this;
  }
  mint operator++(int) {
    mint result = *this;
    ++*this;
    return result;
  }
  mint operator--(int) {
    mint result = *this;
    --*this;
    return result;
  }

  mint &operator+=(const mint &rhs) {
    _v += rhs._v;
    if (_v >= umod()) _v -= umod();
    return *this;
  }
  mint &operator-=(const mint &rhs) {
    _v -= rhs._v;
    if (_v >= umod()) _v += umod();
    return *this;
  }
  mint &operator*=(const mint &rhs) {
    unsigned long long z = _v;
    z *= rhs._v;
    _v = (unsigned int)(z % umod());
    return *this;
  }
  mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }

  mint operator+() const { return *this; }
  mint operator-() const { return mint() - *this; }

  mint pow(long long n) const {
    assert(0 <= n);
    mint x = *this, r = 1;
    while (n) {
      if (n & 1) r *= x;
      x *= x;
      n >>= 1;
    }
    return r;
  }

  friend mint operator+(const mint &lhs, const mint &rhs) {
    return mint(lhs) += rhs;
  }
  friend mint operator-(const mint &lhs, const mint &rhs) {
    return mint(lhs) -= rhs;
  }
  friend mint operator*(const mint &lhs, const mint &rhs) {
    return mint(lhs) *= rhs;
  }
  friend mint operator/(const mint &lhs, const mint &rhs) {
    return mint(lhs) /= rhs;
  }
  friend bool operator==(const mint &lhs, const mint &rhs) {
    return lhs._v == rhs._v;
  }
  friend bool operator!=(const mint &lhs, const mint &rhs) {
    return lhs._v != rhs._v;
  }

 private:
  unsigned int _v;
  static constexpr unsigned int umod() { return m; }
};
template <typename T> class FenwickTree {
  vector<T> tree;
  T prefix_sum(size_t p) const {
    T res = 0;
    for (--p; p < tree.size(); p = (p & (p + 1)) - 1) res = res + tree[p];
    return res;
  }

 public:
  FenwickTree(size_t n): tree(n) {}
  void add_point(size_t p, T const &val) {
    for (; p < tree.size(); p |= p + 1) tree[p] += val;
  }
  T get_sum(size_t l, size_t r) const { return prefix_sum(r) - prefix_sum(l); }
  size_t size(void) const { return tree.size(); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui k;
  cin >> n >> k;
  FenwickTree<static_modint<P>> f(k + 1);
  f.add_point(0, 1);
  for (size_t t = 0; t < n; ++t) {
    ui a;
    cin >> a;
    FenwickTree<static_modint<P>> g(k + 1);
    for (ui j = 0; j <= k; ++j)
      g.add_point(j, f.get_sum(j > a ? j - a : 0, j + 1));
    f = g;
  }
  cout << f.get_sum(k, k + 1).val();
  return 0;
}