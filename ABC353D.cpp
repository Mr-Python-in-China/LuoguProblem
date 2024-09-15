#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
uli constexpr P = 998244353;
array<uli, 11> pow10 = {1,         10,         100,        1000,
                        10000,     100000,     1000000,    10000000,
                        100000000, 1000000000, 10000000000};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  uli sum = 0, ans = 0;
  for (size_t i = 0; i < n; ++i) {
    (ans += sum * pow10[log10(a[i]) + 1] + a[i] * uli(i)) %= P;
    (sum += a[i]) %= P;
  }
  cout << ans;
  return 0;
}