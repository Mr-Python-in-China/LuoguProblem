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
    size_t n;
    cin >> n;
    vector<ui> a(n);
    for (ui &i : a) cin >> i;
    ui l = 1, r = 1e9;
    while (l < r) {
      ui mid = (l + r + 1) / 2;
      int last = 0, minp = 0, now = (a[0] >= mid ? 1 : -1),
          ans = numeric_limits<int>::min();
      for (size_t i = 1; i < n; ++i) {
        minp = min(minp, last);
        last = now, now += (a[i] >= mid ? 1 : -1);
        ans = max(ans, now - minp);
      }
      ans > 0 ? l = mid : r = mid - 1;
    }
    cout << l << '\n';
  }
  return 0;
}