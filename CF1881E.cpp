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
    cin >> n;
    vector<size_t> a(n);
    for (size_t& i : a) cin >> i;
    vector<size_t> to_nxt(n + 1);
    vector<size_t> dp(n + 1, numeric_limits<size_t>::max() >> 1);
    dp.back() = 0;
    for (size_t i = n - 1; i < n; --i)
      if (i + a[i] < n) {
        dp[i] = dp[i + a[i] + 1 + to_nxt[i + a[i] + 1]] + to_nxt[i + a[i] + 1];
      } else
        to_nxt[i] = to_nxt[i + 1] + 1;
    size_t ans = numeric_limits<size_t>::max();
    for (size_t i = 0; i < n; ++i) ans = min(ans, dp[i] + i);
    if (ans >= numeric_limits<size_t>::max() >> 1)
      cout << n << '\n';
    else
      cout << ans << '\n';
  }
  return 0;
}