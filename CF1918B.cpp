#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    ui a, b;
    cin >> a >> b;
    uli x = a / __gcd(a, b), y = b / __gcd(a, b);
    uli ans = x * y * __gcd(a, b);
    if (x == 1) ans *= y;
    cout << ans << '\n';
  }
  return 0;
}