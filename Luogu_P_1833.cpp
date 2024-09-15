#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
istream& separator(istream& is) { return is.ignore(); }
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui t, n;
  {
    ui sh, sm, eh, em;
    cin >> sh >> separator >> sm >> eh >> separator >> em >> n;
    t = (eh * 60 + em) - (sh * 60 + sm);
  }
  vector<pair<ui, ui>> items;
  for (size_t i = 0; i < n; ++i) {
    ui tt, c, p;
    cin >> tt >> c >> p;
    if (p == 0) p = 1000;
    for (ui j = 1; p >= j; p -= j, j <<= 1) items.emplace_back(tt * j, c * j);
    if (p) items.emplace_back(tt * p, c * p);
  }
  vector<ui> f(t + 1);
  for (pair<ui, ui>& i : items)
    for (ui j = t; j >= i.first; --j)
      f[j] = max(f[j], f[j - i.first] + i.second);
  cout << f.back();
  return 0;
}