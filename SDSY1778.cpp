#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui a, b;
  cin >> a >> b;
  vector<vector<double>> f(
      a + 1, vector<double>(b + 1, -numeric_limits<double>::infinity()));
  f[a][b] = 0;
  for (ui i = a; i > 0; --i)
    for (ui j = b; j > 0; --j) {
      f[i - 1][j] = (f[i][j] + 1) * i / (i + j);
      f[i][j - 1] = (f[i][j] - 1) * j / (i + j);
    }
  for (ui i = a; i > 0; --i) f[i - 1][0] = f[i][0] + 1;
  for (ui j = b; j > 0; --j) f[0][j - 1] = f[0][j] + 1;
  return 0;
}