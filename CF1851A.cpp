#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, ans = 0;
    int m, k, h;
    cin >> n >> m >> k >> h;
    while (n--) {
      int x;
      cin >> x;
      ans += x != h && (h - x) % k == 0 && abs(h - x) / k < m;
    }
    cout << ans << '\n';
  }
  return 0;
}