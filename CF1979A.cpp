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
    size_t n;
    ui a;
    cin >> n >> a;
    ui ans = numeric_limits<ui>::max();
    for (size_t i = 1; i < n; ++i) {
      ui b;
      cin >> b;
      ans = min(ans, max(a, b));
      a = b;
    }
    cout << ans - 1 << '\n';
  }
  return 0;
}