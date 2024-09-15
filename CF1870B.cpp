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
    size_t n, m;
    cin >> n >> m;
    vector<ui> a1(n);
    for (ui& i : a1) cin >> i;
    vector<ui> a2(a1);
    ui orp = 0;
    for (size_t i = 0; i < m; ++i) {
      ui x;
      cin >> x;
      orp |= x;
    }
    for (ui& i : a2) i |= orp;
    ui ans1 = 0, ans2 = 0;
    for (ui const& i : a1) ans1 ^= i;
    for (ui const& i : a2) ans2 ^= i;
    cout << min(ans1, ans2) << ' ' << max(ans1, ans2) << '\n';
  }
  return 0;
}