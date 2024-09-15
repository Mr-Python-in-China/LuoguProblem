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
  ui r = 0, p = 0, s = 0;
  for (size_t i = 0; i < n; ++i) {
    char c;
    cin >> c;
    ui nr = r, np = p, ns = s;
    if (c == 'R') np = max(r, s) + 1, nr = max(p, s);
    if (c == 'P') ns = max(r, p) + 1, np = max(r, s);
    if (c == 'S') nr = max(p, s) + 1, ns = max(r, p);
    r = nr, p = np, s = ns;
  }
  cout << max({r, p, s});
  return 0;
}