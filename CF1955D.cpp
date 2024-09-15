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
    size_t n, m, k;
    cin >> n >> m >> k;
    vector<ui> a(n), b(m);
    map<ui, size_t> cnta, cntb;
    for (ui& i : a) cin >> i;
    for (ui& j : b) cin >> j, ++cntb[j];
    size_t t = 0, ans = 0;
    vector<ui>::const_iterator it = a.cbegin(), jt = a.cbegin();
    for (size_t i = 0; i < m; ++i, ++jt)
      if (cnta[*jt]++ < cntb[*jt]) ++t;
    if (t >= k) ++ans;
    for (; jt < a.end(); ++it, ++jt) {
      if (cnta[*jt]++ < cntb[*jt]) ++t;
      if (--cnta[*it] < cntb[*it]) --t;
      if (t >= k) ++ans;
    }
    cout << ans << '\n';
  }
  return 0;
}