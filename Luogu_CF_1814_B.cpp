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
    ui ans = numeric_limits<ui>::max();
    for (ui i = 1; i <= 3e5; ++i)
      ans = min(ans, (a / i) + (a % i != 0) + (b / i) + (b % i != 0) + (i - 1));
    cout << ans << '\n';
  }
  return 0;
}