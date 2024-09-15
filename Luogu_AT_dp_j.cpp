#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  size_t c3 = 0, c2 = 0, c1 = 0;
  for (size_t i = 0; i < n; ++i) {
    char c;
    cin >> c;
    (c == '3' ? ++c3 : c == '2' ? ++c2 : c == '1' ? ++c1 : throw);
  }
  vector<vector<vector<double>>> f(
      n + 2, vector<vector<double>>(n + 2, vector<double>(n + 2)));
  for (size_t k = 0; k <= n; ++k)
    for (size_t j = 0; j <= n; ++j)
      for (size_t i = 0; i <= n; ++i)
        if (i || j || k) {
          f[i][j][k] = n / double(i + j + k);
          if (i) f[i][j][k] += i * f[i - 1][j][k] / (i + j + k);
          if (j) f[i][j][k] += j * f[i + 1][j - 1][k] / (i + j + k);
          if (k) f[i][j][k] += k * f[i][j + 1][k - 1] / (i + j + k);
        }
  cout << setprecision(16) << f[c1][c2][c3];
  return 0;
}