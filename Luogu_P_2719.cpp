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
  if (n == 2) cout << "0.0000", exit(0);
  vector<vector<float>> f(n / 2 + 1, vector<float>(n / 2 + 1));
  f[n / 2][n / 2] = 1;
  for (size_t i = n; i > 0; --i)
    for (size_t x = 0, y = i - x; x <= n / 2; ++x, --y)
      if (y <= n / 2) {
        if (x == 0)
          f[x][y - 1] += f[x][y];
        else if (y == 0)
          f[x - 1][y] += f[x][y];
        else
          f[x - 1][y] += f[x][y - 1] = f[x][y] / 2;
      }
  cout << fixed << setprecision(4) << f[2][0] + f[0][2];
  return 0;
}