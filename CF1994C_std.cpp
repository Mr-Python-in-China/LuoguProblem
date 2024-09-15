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
    ui x;
    cin >> n >> x;
    vector<ui> a(n);
    for (ui &i : a) cin >> i;
    uli ans = 0;
    for (size_t i = 0; i < n; ++i) {
      uli t = 0;
      for (size_t j = i; j < n; ++j) {
        t += a[j];
        if (t > x) t = 0;
        if (t > 0) ++ans;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}