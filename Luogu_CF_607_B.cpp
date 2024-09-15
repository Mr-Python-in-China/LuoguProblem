#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<usi> a(n);
  for (usi& i : a) cin >> i;
  vector<vector<usi>> f(n, vector<usi>(n + 1, numeric_limits<usi>::max() / 2));
  for (size_t i = 0; i < n; ++i) f[i][i] = f[i][i + 1] = 1;
  for (size_t len = 2; len <= n; ++len)
    for (size_t i = 0, j = len; j <= n; ++i, ++j) {
      if (a[i] == a[j - 1]) f[i][j] = f[i + 1][j - 1];
      for (size_t k = i + 1; k < j; ++k)
        f[i][j] = min<usi>(f[i][j], f[i][k] + f[k][j]);
    }
  cout << f[0][n];
  return 0;
}