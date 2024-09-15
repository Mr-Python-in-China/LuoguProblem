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
    ui x, y;
    cin >> n >> x >> y;
    uli ans = 0;
    map<pair<ui, ui>, ui> mod;
    for (size_t i = 0; i < n; ++i) {
      ui v;
      cin >> v;
      ans += mod[{v % x ? x - v % x : 0, v % y}];
      ++mod[{v % x, v % y}];
    }
    cout << ans << '\n';
  }
  return 0;
}