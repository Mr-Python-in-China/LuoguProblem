#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<ui> q(n), a(n), b(n);
  for (ui& i : q) cin >> i;
  for (ui& i : a) cin >> i;
  for (ui& i : b) cin >> i;
  ui ac = numeric_limits<ui>::max() >> 1;
  for (size_t i = 0; i < n; ++i)
    if (a[i]) ac = min(ac, q[i] / a[i]);
  for (size_t i = 0; i < n; ++i) q[i] -= a[i] * ac;
  ui ans = 0;
  for (; ac != -1; --ac) {
    ui bc = numeric_limits<ui>::max() >> 1;
    for (size_t i = 0; i < n; ++i)
      if (b[i]) bc = min(bc, q[i] / b[i]);
    ans = max(ans, ac + bc);
    for (size_t i = 0; i < n; ++i) q[i] += a[i];
  }
  cout << ans;
  return 0;
}