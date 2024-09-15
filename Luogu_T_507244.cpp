#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
const ui Nan = numeric_limits<ui>::max();
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui s;
  size_t n;
  fin >> s >> n;
  vector<pair<ui, ui>> a(n);
  for (pair<ui, ui>& i : a) fin >> i.first >> i.second;
  ui ans = 0;
  for (pair<ui, ui> const& d : a)
    if (d.first <= s) {
      vector<array<ui, 2>> f(s + 1, {Nan, Nan});
      f[d.first][0] = d.second;
      for (pair<ui, ui> const& i : a)
        if (&i != &d) {
          vector<array<ui, 2>> g(f);
          for (ui j = d.first + i.first; j <= s; ++j)
            if (f[j - i.first][0] != Nan)
              g[j][0] = max(g[j][0] != Nan ? g[j][0] : 0,
                            f[j - i.first][0] + i.second);
          for (ui j = d.first + i.first; j <= s; ++j)
            if (f[j - i.first][1] != Nan)
              g[j][1] = max(g[j][1] != Nan ? g[j][1] : 0,
                            f[j - i.first][1] + i.second);
          for (ui j = d.first + d.first; j <= s; ++j)
            if (f[j - d.first][0] != Nan)
              g[j][1] = max(g[j][1] != Nan ? g[j][1] : 0,
                            f[j - d.first][0] + i.second);
          f = g;
        }
      for (auto const& i : f) {
        if (i[0] != Nan) ans = max(ans, i[0]);
        if (i[1] != Nan) ans = max(ans, i[1]);
      }
    }
  fout << ans;
  return 0;
}