#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<vector<int>> dst(n, vector<int>(n, numeric_limits<int>::max() / 2));
  while (m--) {
    size_t u, v;
    int w;
    cin >> u >> v >> w;
    --u, --v;
    dst[u][v] = w;
  }
  for (size_t k = 0; k < n; ++k)
    for (size_t i = 0; i < n; ++i)
      for (size_t j = 0; j < n; ++j)
        dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
  vector<vector<int>> dp(1 << n,
                         vector<int>(n, numeric_limits<int>::max() / 2));
  for (size_t i = 0; i < n; ++i) dp[1 << i][i] = 0;
  for (size_t i = 0; i < (1 << n); ++i)
    if (__builtin_popcount(i) > 1)
      for (size_t j = 0; j < n; ++j)
        if ((i | (1 << j)) == i)
          for (size_t k = 0; k < n; ++k)
            if (k != j && (i & (1 << k)))
              dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + dst[k][j]);
  int ans = numeric_limits<int>::max();
  for (size_t i = 0; i < n; ++i) ans = min(ans, dp[(1 << n) - 1][i]);
  if (ans >= numeric_limits<int>::max() / 8)
    cout << "No";
  else
    cout << ans;
  return 0;
}