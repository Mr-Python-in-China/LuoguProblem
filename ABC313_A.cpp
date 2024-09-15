#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  ui x;
  cin >> x;
  ui ans = 0;
  for (size_t i = 1; i < n; i++) {
    ui val;
    cin >> val;
    if (x + ans <= val) ans = val + 1 - x;
  }
  cout << ans;
  return 0;
}