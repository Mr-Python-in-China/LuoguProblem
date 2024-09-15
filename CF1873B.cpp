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
    for (ui& i : a) cin >> i;
    ui ans = 0;
    for (ui& i : a) {
      ++i;
      ui times = 1;
      for (ui const& j : a) times *= j;
      ans = max(ans, times);
      --i;
    }
    cout << ans << '\n';
  }
  return 0;
}