#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
/// @param n 苹果数量
/// @param k 上限
/// @param m 盘子数量
uli f(ui n, ui k, ui m) {
  static array<array<array<uli, 11>, 501>, 501> mem = {};
  if (mem[n][k][m])
    ;
  else if (n < m)
    mem[n][k][m] = 0;
  else if (k == 0)
    mem[n][k][m] = 0;
  else if (m == 1)
    mem[n][k][m] = k >= n;
  else
    mem[n][k][m] = f(n - m, k - 1, m - 1) + f(n - m, k - 1, m);
  if (mem[n][k][m] == 0) mem[n][k][m] = ~0;
  return ~mem[n][k][m] ? mem[n][k][m] : 0;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n, k, m;
  cin >> n >> k >> m;
  cout << f(n, m, k);
  return 0;
}
