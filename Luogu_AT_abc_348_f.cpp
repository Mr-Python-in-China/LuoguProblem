#pragma optimize("Ofast")
#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<vector<usi>> a(n, vector<usi>(m));
  ui ans = 0;
  for (size_t i = 0; i < n; ++i) {
    for (usi& j : a[i]) cin >> j;
    for (size_t j = 0; j < i; ++j) {
      usi d = 0;
      for (size_t k = 0; k < m; ++k) d += a[i][k] == a[j][k];
      ans += d % 2 == 1;
    }
  }
  cout << ans;
  return 0;
}