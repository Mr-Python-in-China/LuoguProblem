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
    ui n, y;
    size_t x;
    cin >> n >> x >> y;
    vector<ui> c(x);
    for (ui& i : c) cin >> i;
    sort(c.begin(), c.end());
    vector<ui> dd;
    ui ans = n - 2;
    for (size_t i = 1; i < x; ++i) {
      ui d = c[i] - c[i - 1] - 1;
      if (d > 1) dd.push_back(d);
    }
    if (c.front() + n - c.back() - 1 > 1) {
      ui d = c.front() + n - c.back() - 1;
      if (d > 1) dd.push_back(d);
    }
    sort(dd.begin(), dd.end(), [](ui x, ui y) {
      return (x & 1) == (y & 1) ? x < y : (x & 1) > (y & 1);
    });
    for (ui d : dd) {
      ui t = min(d / 2, y);
      y -= t, d -= t * 2;
      if (d > 1) ans -= d;
    }
    cout << ans << '\n';
  }
  return 0;
}