#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string s, t;
  cin >> s >> t;
  vector<vector<usi>> dp(s.size(), vector<usi>(t.size()));
  dp[0][0] = s[0] != t[0];
  for (size_t i = 1; i < s.size(); ++i)
    dp[i][0] = s[i] == t[0] ? i : dp[i - 1][0] + 1;
  for (size_t j = 1; j < t.size(); ++j)
    dp[0][j] = s[0] == t[j] ? j : dp[0][j - 1] + 1;
  for (size_t i = 1; i < s.size(); ++i)
    for (size_t j = 1; j < t.size(); ++j)
      dp[i][j] = s[i] == t[j]
                     ? dp[i - 1][j - 1]
                     : min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
  cout << dp.back().back();
  return 0;
}