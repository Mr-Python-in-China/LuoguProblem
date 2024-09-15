#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t m;
    ui x;
    cin >> m >> x;
    vector<pair<ui, ui>> a(m);
    for (pair<ui, ui> &i : a) cin >> i.first >> i.second;
    vector<li> f(accumulate(a.begin(), a.end(), ui(0),
                            [](auto s, auto b) { return s += b.second; }) +
                     1,
                 numeric_limits<li>::min());
    f[0] = 0;
    for (pair<ui, ui> i : a) {
      vector<li> g(f.size());
      for (ui j = 0; j < f.size(); ++j) g[j] = f[j] + x;
      for (ui j = i.second; j < f.size(); ++j)
        if (f[j - i.second] >= i.first)
          g[j] = max(g[j], f[j - i.second] - i.first + x);
      f = g;
    }
    cout << f.rend() -
                find_if(f.rbegin(), f.rend(), [](li x) { return x >= 0; }) - 1
         << '\n';
  }
  return 0;
}