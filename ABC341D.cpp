#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli n, m, k;
  cin >> n >> m >> k;
  uli lcm = n * m / __gcd(n, m);
  uli d = lcm / n + lcm / m - 2;
  uli ans = k / d * lcm;
  k %= d;
  if (k == 0)
    cout << (ans -= min(n, m));
  else {
    uli t = 0, x = 0, y = 0;
    for (uli i = 0; i < k; ++i) t = (x * n + n < y * m + m ? ++x * n : ++y * m);
    cout << (ans += t);
  }
  return 0;
}