#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  array<array<uli, 10>, 13> dp({});
  for (uli i = 1, p = 1; i < 13; ++i, p *= 10)
    for (size_t j = 0; j < 10; ++j) dp[i][j] = dp[i - 1][j] * 10 + p;

  uli a, b;
  cin >> a >> b;

  return 0;
}