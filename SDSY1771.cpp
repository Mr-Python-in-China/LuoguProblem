#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 1000000007;
template <typename T, size_t N, size_t M> struct matrix {
  array<array<T, M>, N> m{};
  template <size_t L>
  friend matrix<T, N, L> operator*(matrix<T, N, M> const& a,
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
  matrix& operator*=(matrix<T, N, N> const& x) { return *this = *this * x; }
};
template <typename T, size_t N>
matrix<T, N, N> quick_pow(matrix<T, N, N> a, uli k) {
  matrix<T, N, N> ans;
  for (size_t i = 0; i < N; ++i) ans.m[i][i] = 1;
  while (k) {
    if (k & 1) ans *= a;
    a *= a;
    k >>= 1;
  }
  return ans;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n, m;
  if (!(cin >> n >> m)) return 0;
  if (n == 1)
    cout << uli(m) * (m - 1) % P;
  else {
    --m;
    matrix<uli, 1, 2> a;
    a.m[0][0] = 1, a.m[0][1] = 0;
    matrix<uli, 2, 2> t;
    t.m[0][0] = 0, t.m[0][1] = 1, t.m[1][0] = m - 1, t.m[1][1] = m - 2;
    cout << uli((a * quick_pow(t, n - 1)).m[0][1]) * (m - 1) % P * n % P *
                (n + 1) % P;
  }
  cout << '\n';
  return main();
}