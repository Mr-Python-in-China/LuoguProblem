#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<vector<bool>> a(n, vector<bool>(n)), b(n, vector<bool>(n));
  for (size_t i = 0; i < n; ++i)
    for (size_t j = i + 1; j < n; ++j) {
      char c;
      cin >> c;
      a[i][j] = c == '1';
    }
  for (size_t i = 0; i < n; ++i) {
    b[i][i] = 1;
    for (size_t j = 0; j < n; ++j)
      for (size_t k = j + 1; k < n; ++k)
        if (a[j][k]) b[i][k] = b[i][k] ^ b[i][j];
  }
  size_t ans = 0;
  for (size_t i = 0; i < n; ++i)
    for (size_t j = i + 1; j < n; ++j) ans += b[i][j];
  cout << ans;
  return 0;
}