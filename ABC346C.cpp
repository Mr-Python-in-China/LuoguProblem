#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui k;
  cin >> n >> k;
  uli ans = k * (k + 1ll) / 2;
  unordered_set<ui> vis;
  for (size_t i = 0; i < n; ++i) {
    ui x;
    cin >> x;
    if (x <= k && !vis.count(x)) ans -= x;
    vis.insert(x);
  }
  cout << ans;
  return 0;
}