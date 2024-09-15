#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 998244353;
template <typename T, size_t N, size_t M> struct matrix {
  array<array<T, M>, N> m;
  constexpr matrix(void): m({}) {}
  template <size_t L>
  constexpr friend matrix<T, N, L> operator*(matrix<T, N, M> const& a,
                                             matrix<T, M, L> const& b) {
    matrix<T, N, L> ans;
    for (size_t i = 0; i < N; ++i)
      for (size_t j = 0; j < L; ++j)
        for (size_t k = 0; k < M; ++k) {
          (ans.m[i][j] += a.m[i][k] * b.m[k][j]) %= P;
          if (ans.m[i][j] < 0) ans.m[i][j] += P;
        }
    return ans;
  }
  static constexpr matrix identity(void) {
    matrix res;
    for (size_t i = 0; i < N; ++i) res.m[i][i] = 1;
    return res;
  }
  constexpr matrix& operator*=(matrix<T, N, N> const& x) {
    return *this = *this * x;
  }
};
constexpr ui quick_pow(ui a, ui n) {
  uli ans = 1;
  while (n) {
    if (n & 1) (ans *= a) %= P;
    a = uli(a) * a % P;
    n >>= 1;
  }
  return ans;
}
template <typename T, size_t N>
matrix<T, N, N> quick_pow(matrix<T, N, N> a, size_t k) {
  matrix<T, N, N> ans = matrix<T, N, N>::identity();
  while (k) {
    if (k & 1) ans *= a;
    a *= a;
    k >>= 1;
  }
  return ans;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli v = 1;
  uli len = 1;
  deque<pair<uli, uli>> q({
      {1, 1}
  });
  size_t n;
  cin >> n;
  while (n--) {
    char op;
    cin >> op;
    if (op == '1') {
      uli x, y;
      cin >> x >> y;
      matrix<uli, 1, 2> a;
      a.m[0][0] = 0, a.m[0][1] = 1;
      matrix<uli, 2, 2> m;
      m.m[0][0] = 10, m.m[0][1] = 0;
      m.m[1][0] = 1, m.m[1][1] = 1;
      v = ((uli(v) * quick_pow(10, x)) + (a * quick_pow(m, x)).m[0][0] * y) % P;
      len += x;
      q.emplace_back(x, y);
    } else if (op == '2') {
      uli x;
      cin >> x;
      while (x) {
        uli p = min(q.front().first, x);
        matrix<uli, 1, 2> a;
        a.m[0][0] = 0, a.m[0][1] = 1;
        matrix<uli, 2, 2> m;
        m.m[0][0] = 10, m.m[0][1] = 0;
        m.m[1][0] = 1, m.m[1][1] = 1;
        v = (li(v) - li((a * quick_pow(m, p)).m[0][0] *
                        quick_pow(10, len -= p) * q.front().second)) %
                int(P) +
            P;
        if (v >= P) v -= P;
        x -= p, q.front().second -= p;
        if (q.front().second == 0) q.pop_front();
      }
    } else if (op == '3') {
      cout << v << '\n';
    }
  }
  return 0;
}