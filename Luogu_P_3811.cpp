#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
ui P;
template <size_t N> array<ui, N + 1> liner_inv(void) {
  array<ui, N + 1> inv;
  inv[1] = 1;
  for (size_t i = 2; i <= N; ++i) inv[i] = uli(P - P / i) * inv[P % i] % P;
  return inv;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n >> P;
  auto p = liner_inv<size_t(1e7)>();
  for (size_t i = 1; i <= n; ++i) cout << p[i] << '\n';
  return 0;
}