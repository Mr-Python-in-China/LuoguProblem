#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t m;
  cin >> m;
  vector<ui> a(m);
  for (ui& i : a) cin >> i;
  ui ans = accumulate(a.begin(), a.end(), 1) >> 1;
  size_t month = 0;
  for (; month < m; ++month)
    if (a[month] >= ans) {
      cout << ++month << ' ' << ans;
      return 0;
    } else
      ans -= a[month];
  return 0;
}