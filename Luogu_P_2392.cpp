#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  array<size_t, 4> n;
  array<vector<ui>, 4> a;
  for (size_t i = 0; i < 4; ++i) cin >> n[i], a[i].resize(n[i]);
  ui ans = 0;
  for (vector<ui>& r : a) {
    for (ui& i : r) cin >> i;
    ui minx = numeric_limits<ui>::max();
    for (ui i = 0; i < (1 << r.size()); ++i) {
      ui x = 0, y = 0, v = i;
      for (ui j = 0; j < r.size(); ++j, v >>= 1) (v & 1 ? x : y) += r[j];
      minx = min(minx, max(x, y));
    }
    ans += minx;
  }
  cout << ans;
  return 0;
}