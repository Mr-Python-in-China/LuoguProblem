#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
ui constexpr P = 19650827;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<usi> a(n);
  for (usi& i : a) cin >> i;
  vector<vector<pair<ui, ui>>> f(n, vector<pair<ui, ui>>(n + 1));
  for (size_t i = 0; i < n; ++i) f[i][i + 1].first = 1;
  for (size_t len = 2; len <= n; ++len)
    for (size_t i = 0, j = len; j <= n; ++i, ++j) {
      if (a[i] < a[i + 1])
        f[i][j].first += f[i + 1][j].first,
            f[i][j].first >= P ? f[i][j].first -= P : 0;
      if (a[i] < a[j - 1])
        f[i][j].first += f[i + 1][j].second,
            f[i][j].first >= P ? f[i][j].first -= P : 0;
      if (a[j - 1] > a[i])
        f[i][j].second += f[i][j - 1].first,
            f[i][j].second >= P ? f[i][j].second -= P : 0;
      if (a[j - 1] > a[j - 2])
        f[i][j].second += f[i][j - 1].second,
            f[i][j].second >= P ? f[i][j].second -= P : 0;
    }
  cout << (f[0][n].first + f[0][n].second) % P;
  return 0;
}