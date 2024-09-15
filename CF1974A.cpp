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
    ui x, y;
    cin >> x >> y;
    ui ans = 0;
    while (x >= 7 && y >= 2) ++ans, x -= 7, y -= 2;
    if (y < 2) x += y * 4, y = 0, ans += (x + 14) / 15, x = 0;
    if (x < 7) ans += (y + 1) / 2, x = 0, y = 0;
    cout << ans << '\n';
  }
  return 0;
}