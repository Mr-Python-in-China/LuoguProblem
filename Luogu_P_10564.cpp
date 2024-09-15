#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
array<ui, 27 * 27 * 27 * 27 * 27> c;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  c.fill(numeric_limits<ui>::max());
  size_t q;
  fin >> q;
  while (q--) {
    char op;
    string s;
    fin >> op >> s;
    if (op == '1') {
      ui x;
      fin >> x;
      for (ui i = 0; i < (1u << s.size()); ++i) {
        ui t = 0;
        for (ui j = 0; j < 5; ++j)
          t = t * 27 + ((i >> j) & 1 ? s[j] - 'a' : 26);
        c[t] = min(c[t], x);
      }
    } else if (op == '2') {
      ui u = 0, v = numeric_limits<ui>::max();
      for (ui i = 0; i < (1u << s.size()); ++i) {
        ui t = 0;
        for (ui j = 0; j < 5; ++j)
          t = t * 27 + ((i >> j) & 1 ? s[j] - 'a' : 26);
        if (c[t] == numeric_limits<ui>::max())
          continue;
        else if (__builtin_popcount(i) > u)
          u = __builtin_popcount(i), v = c[t];
        else if (__builtin_popcount(i) == u)
          v = min(v, c[t]);
      }
      fout << v << '\n';
    }
  }
  return 0;
}