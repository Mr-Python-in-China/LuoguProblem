#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
vector<ui> stk({0, 1});
vector<ui> anstk;
size_t ansval;
size_t n, k;
void dfs(size_t d) {
  if (d == 0) {
    return;
    vector<vector<bool>> dp(n + 1,
                            vector<bool>(min<size_t>(stk.back() * n + 1, 500)));
    dp[0][0] = true;
    for (size_t i = 1; i <= n; i++)
      for (ui& j : stk)
        for (size_t l = dp[i].size() - 1;
             l >= j && l != numeric_limits<size_t>::max(); --l)
          if (dp[i - 1][l - j]) dp[i][l] = true;
    size_t i = 0;
    for (; dp[n][i]; ++i);
    if (i > ansval) ansval = i, anstk = stk;
    return;
  }
  for (size_t i = stk.back() + 2; i <= stk.back() * n + 1; ++i) {
    stk.push_back(i);
    dfs(d - 1);
    stk.pop_back();
  }
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> k;
  dfs(k - 1);
  for (ui const& i : anstk)
    if (i != 0) cout << i << ' ';
  cout << '\n';
  cout << "MAX=" << ansval - 1;
  return 0;
}