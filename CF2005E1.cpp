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
  size_t T;
  fin >> T;
  while (T--) {
    size_t l, n, m;
    fin >> l >> n >> m;
    vector<ui> a(l);
    for (ui& i : a) fin >> i;
    vector<vector<ui>> b(n, vector<ui>(m));
    for (vector<ui>& i : b)
      for (ui& j : i) fin >> j;
    vector<vector<bool>> f(n, vector<bool>(m));
    for_each(a.rbegin(), a.rend(), [&](size_t target) {
      vector<vector<bool>> g(n, vector<bool>(m));
      vector<vector<bool>> noTrue(n + 1, vector<bool>(m + 1, true));
      for (size_t i = n - 1; i < n; --i)
        for (size_t j = m - 1; j < m; --j) {
          noTrue[i][j] = noTrue[i + 1][j] & noTrue[i][j + 1] & !f[i][j];
          if (b[i][j] == target && noTrue[i + 1][j + 1]) g[i][j] = true;
        }
      f = move(g);
    });
    bool ans = false;
    for (auto const& i : f)
      for (auto j : i) ans |= j;
    fout << (ans ? "T\n" : "N\n");
  }
  return 0;
}