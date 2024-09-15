#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n, x;
  cin >> n >> x;
  vector<ui> dp(x + 1);
  while (n--) {
    ui lose, win, use;
    cin >> lose >> win >> use;
    for (ui i = x; i != -1 && i >= use; i--)
      dp[i] = max(dp[i] + lose, dp[i - use] + win);
    for (ui i = 0; i < use; i++) dp[i] += lose;
  }
  cout << dp[x] * 5;
  return 0;
}