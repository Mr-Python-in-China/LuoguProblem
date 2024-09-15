#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using ic = signed char;
template <typename T> T sqr(T x) { return x * x; }
void color(size_t x, size_t y, vector<vector<ic>>& c, bool b, ui d) {
  if (c[x][y] == -1) {
    c[x][y] = b;
    for (ui i = 0; i * i <= d; ++i) {
      double j = sqrt(d - i * i);
      if (ui(j) * ui(j) + ui(i) * ui(i) != d) continue;
      if (ui(x) + ui(i) < c.size() && ui(y) + ui(j) < c[ui(x) + ui(i)].size())
        color(ui(x) + ui(i), ui(y) + ui(j), c, !b, d);
      if (ui(x) - ui(i) < c.size() && ui(y) + ui(j) < c[ui(x) - ui(i)].size())
        color(ui(x) - ui(i), ui(y) + ui(j), c, !b, d);
      if (ui(x) + ui(i) < c.size() && ui(y) - ui(j) < c[ui(x) + ui(i)].size())
        color(ui(x) + ui(i), ui(y) - ui(j), c, !b, d);
      if (ui(x) - ui(i) < c.size() && ui(y) - ui(j) < c[ui(x) - ui(i)].size())
        color(ui(x) - ui(i), ui(y) - ui(j), c, !b, d);
    }
  } else if (c[x][y] != b)
    throw;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui d0, d1;
  cin >> n >> d0 >> d1;
  vector<vector<ic>> c0(n * 2, vector<ic>(n * 2, -1)),
      c1(n * 2, vector<ic>(n * 2, -1));
  for (size_t i = 0; i < n * 2; ++i)
    for (size_t j = 0; j < n * 2; ++j) {
      if (c0[i][j] == -1) color(i, j, c0, 0, d0);
      if (c1[i][j] == -1) color(i, j, c1, 0, d1);
    }
  ui x1 = 0, x2 = 0, x3 = 0, x4 = 0;
  for (size_t i = 0; i < n * 2; ++i)
    for (size_t j = 0; j < n * 2; ++j)
      ++(c0[i][j] ? c1[i][j] ? x1 : x2 : c1[i][j] ? x3 : x4);
  ui mx = max({x1, x2, x3, x4});
  ic tt = mx == x1 ? 1 : mx == x2 ? 2 : mx == x3 ? 3 : mx == x4 ? 4 : throw;
  ui t = n * n;
  for (size_t i = 0; i < n * 2; ++i)
    for (size_t j = 0; j < n * 2; ++j)
      if ((c0[i][j] ? c1[i][j] ? 1 : 2 : c1[i][j] ? 3 : 4) == tt) {
        cout << i << ' ' << j << '\n';
        if (!--t) return 0;
      }
  return 0;
}