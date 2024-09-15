#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m1, m2;
  fin >> n;
  fin >> m1;
  vector<vector<bool>> mpx(n, vector<bool>(n)), mpy(n, vector<bool>(n));
  while (m1--) {
    size_t x, y;
    fin >> x >> y;
    --x, --y;
    mpx[x][y] = mpx[y][x] = true;
  }
  fin >> m2;
  while (m2--) {
    size_t x, y;
    fin >> x >> y;
    --x, --y;
    mpy[x][y] = mpy[y][x] = true;
  }
  vector<vector<size_t>> a(n, vector<size_t>(n));
  for (size_t i = 0; i < n; ++i)
    for (size_t j = i + 1; j < n; ++j) {
      fin >> a[i][j];
      a[j][i] = a[i][j];
    }
  vector<size_t> p(n);
  iota(p.begin(), p.end(), 0);
  ui v = numeric_limits<ui>::max();
  do {
    vector<size_t> rp(n);
    for (size_t i = 0; i < n; ++i) rp[p[i]] = i;
    vector<vector<bool>> nmp(n, vector<bool>(n));
    for (size_t i = 0; i < n; ++i)
      for (size_t j = 0; j < n; ++j) nmp[i][j] = mpy[p[i]][p[j]];
    ui ans = 0;
    for (size_t i = 0; i < n; ++i)
      for (size_t j = 0; j < n; ++j)
        if (nmp[i][j] != mpx[i][j])
          nmp[i][j] = !nmp[i][j], nmp[j][i] = !nmp[j][i],
          ans += a[p[i]][p[j]];
    v = min(ans, v);
  } while (next_permutation(p.begin(), p.end()));
  fout << v;
  return 0;
}