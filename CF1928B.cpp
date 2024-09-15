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
    sort(a.begin(), a.end()), a.erase(unique(a.begin(), a.end()), a.end());
    size_t ans = 0;
    for (vector<ui>::const_iterator it = a.cbegin(), jt = it; it < a.cend();
         ++it) {
      while (jt < a.cend() && *jt - *it < n) ++jt;
      ans = max<size_t>(ans, jt - it);
    }
    cout << ans << '\n';
  }
  return 0;
}