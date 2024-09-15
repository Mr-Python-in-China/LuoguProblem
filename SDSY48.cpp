#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n, k;
  cin >> n >> k;
  if (k == 1)
    cout << n;
  else if (k == 2) {
    cout << (n ^ (1 << (31 - __builtin_clz(n)))) * 2 + 1;
  } else {
    ui ans = 0;
    for (ui i = 1; i <= n; ++i) (ans += k) %= i;
    cout << ans + 1;
  }
  return 0;
}