#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    ui ans = 0;
    ui lst;
    cin >> lst;
    for (size_t i = 1; i < n; i++) {
      ui now;
      cin >> now;
      if (now < lst) ans = max(ans, lst);
      lst = now;
    }
    cout << ans << '\n';
  }
  return 0;
}