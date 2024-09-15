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
    map<ui, ui> cnt;
    for (size_t i = 0; i < n; ++i) {
      ui x;
      cin >> x;
      ++cnt[x];
    }
    uli ans = 0;
    uli sum = 0;
    for (pair<ui, size_t> const& i : cnt) {
      if (i.second >= 3)
        ans += uli(i.second) * (i.second - 1) * (i.second - 2) / 6;
      if (i.second >= 2) ans += uli(i.second) * (i.second - 1) / 2 * sum;
      sum += i.second;
    }
    cout << ans << '\n';
  }
  return 0;
}