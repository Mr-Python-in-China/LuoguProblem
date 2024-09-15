#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> constexpr bool is_prime(T n) {
  if (n < 2) return false;
  for (T i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
template <typename T, T P> class ModInt;
template <typename T = li, T P = 1'000'000'007> T ksm(ModInt<T, P> a, T n) {
  ModInt<T, P> ans = 1;
  while (n) {
    if (n & 1) ans *= a;
    ans *= ans;
    n >>= 1;
  }
  return ans;
}
template <typename T = li, T P = 1'000'000'007> class ModInt {
  T x;

 public:
  ModInt(void): x() {}
  ModInt(T _x): x(_x % P) {
    if (x < 0) x += P;
  }
  operator T(void) { return x; }
  ModInt& operator+=(T v) {
    (x += v) %= P;
    return *this;
  }
  ModInt& operator-=(T v) {
    (x -= v) %= P;
    if (x < 0) x += P;
    return *this;
  }
  ModInt& operator*=(T v) {
    (x *= v) %= P;
    return *this;
  }
  ModInt& operator/=(T v) {
    static_assert(is_prime(P));
    (x *= ksm<T, P>(v, P - 2)) %= P;
    return *this;
  }
  ModInt& operator+=(ModInt v) { return *this += T(v); }
  ModInt& operator-=(ModInt v) { return *this -= T(v); }
  ModInt& operator*=(ModInt v) { return *this *= T(v); }
  ModInt& operator/=(ModInt v) { return *this /= T(v); }
  ModInt operator+(T v) const {
    ModInt<T, P> tmp = *this;
    return tmp += v;
  }
  ModInt operator-(T v) const {
    ModInt<T, P> tmp = *this;
    return tmp -= v;
  }
  ModInt operator*(T v) const {
    ModInt<T, P> tmp = *this;
    return tmp *= v;
  }
  ModInt operator/(T v) const {
    ModInt<T, P> tmp = *this;
    return tmp /= v;
  }
  ModInt operator+(ModInt v) const {
    ModInt<T, P> tmp = *this;
    return tmp += v;
  }
  ModInt operator-(ModInt v) const {
    ModInt<T, P> tmp = *this;
    return tmp -= v;
  }
  ModInt operator*(ModInt v) const {
    ModInt<T, P> tmp = *this;
    return tmp *= v;
  }
  ModInt operator/(ModInt v) const {
    ModInt<T, P> tmp = *this;
    return tmp /= v;
  }
  friend istream& operator>>(istream& in, ModInt& x) {
    in >> x.x;
    x.x %= P;
    return in;
  }
};
template <typename T> struct PrefixSum {
  vector<T> sum;
  template <typename InputIterator, typename = _RequireInputIter<InputIterator>>
  PrefixSum(InputIterator begin, size_t n): sum(n + 1) {
    typename vector<T>::iterator it = next(sum.begin());
    while (true) {
      *it = *prev(it) + *begin;
      if (++it >= sum.end()) break;
      ++begin;
    }
  }
  T get_sum(size_t m, size_t n) { return sum[n] - sum[m]; }
  T get_val(size_t m) { return get_sum(m, m + 1); }
  T operator[](size_t m) { return get_val(m); }
  size_t size(void) { return sum.size(); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  PrefixSum<ModInt<li>> sa(istream_iterator<ModInt<li>>(cin), n);
  PrefixSum<ModInt<li>> sb(istream_iterator<ModInt<li>>(cin), n);
  ModInt<li> sumsa, sumsb, sumsasb, ans;
  for (size_t r = 1; r <= n; r++) {
    ans += sa.sum[r] * sb.sum[r] * li(r) - sb.sum[r] * sumsa -
           sa.sum[r] * sumsb + sumsasb;
    sumsa += sa.sum[r], sumsb += sb.sum[r], sumsasb += sa.sum[r] * sb.sum[r];
  }
  cout << ans;
  return 0;
}