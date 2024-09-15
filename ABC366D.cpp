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
  fin >> n;
  vector<vector<vector<ui>>> s(n + 1,
                               vector<vector<ui>>(n + 1, vector<ui>(n + 1)));
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < n; ++j)
      for (size_t k = 0; k < n; ++k) {
        ui x;
        fin >> x;
        s[i + 1][j + 1][k + 1] =
            x + s[i + 1][j + 1][k] + s[i + 1][j][k + 1] + s[i][j + 1][k + 1] +
            s[i][j][k] - s[i + 1][j][k] - s[i][j + 1][k] - s[i][j][k + 1];
      }
  size_t q;
  fin >> q;
  while (q--) {
    size_t x0, x1, y0, y1, z0, z1;
    fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
    --x0, --y0, --z0;
    fout << s[x1][y1][z1] - s[x0][y1][z1] - s[x1][y0][z1] - s[x1][y1][z0] +
                s[x0][y0][z1] + s[x0][y1][z0] + s[x1][y0][z0] - s[x0][y0][z0]
         << '\n';
  }
  return 0;
}