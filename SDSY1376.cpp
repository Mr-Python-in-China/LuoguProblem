#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 1e5 + 3;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui a, b, c, d, k;
  cin >> a >> b >> c >> d >> k;
  vector<vector<ui>> f(b + d + 1, vector<ui>(k + 1));
  f[0][0] = 1;
  for (ui i = 1; i <= b; ++i) {
    f[i][0] = 1;
    for (ui j = 1; j <= k; ++j) f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
  }
  for (ui i = b + 1; i <= b + d; ++i) {
    f[i][0] = 1;
    for (ui j = 1; j <= k; ++j) f[i][j] =
  }
  return 0;
}