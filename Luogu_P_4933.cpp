#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
usi constexpr MAXV = 2e4 + 1;
ui constexpr P = 998244353;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<usi> a(n);
  for (usi& i : a) cin >> i;
  vector<array<ui, MAXV * 2>> f(n, array<ui, MAXV * 2>{});
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < i; ++j)
      (f[i][a[i] - a[j] + MAXV] += f[j][a[i] - a[j] + MAXV] + 1) %= P;
  ui ans = n;
  for (array<ui, MAXV * 2> const& i : f)
    for (ui j : i) (ans += j) %= P;
  cout << ans;
  return 0;
}