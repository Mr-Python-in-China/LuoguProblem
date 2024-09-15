#include <bits/stdc++.h>
// #define debug
using namespace std;
using ui = unsigned int;
using uli = unsigned long long int;
using ld = long double;
using interval = pair<ld, ld>;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ld n, m;
  cin >> n >> m;
  interval ans(0, INFINITY);  // 此处为左闭右开
  for (ui i = 1; i <= n; i++) {
    ld a;
    cin >> a;
    ans.first = max(ans.first, m / (a * i)),
    ans.second = min(ans.second, m / ((a - 1) * i));
#ifdef debug
    cout << a << ' ' << i << ' ' << m / (a * i) << ',' << m / ((a - 1) * i)
         << ' ' << ans.first << ',' << ans.second << '\n';
#endif
  }
  if (isinf(ans.second))
    cout << "xiaogougege";
  else if (ceill(ans.first) >= ans.second)
    cout << 0;
  else
    cout << uli(ceill(ans.second) - ceill(ans.first));
  return 0;
}