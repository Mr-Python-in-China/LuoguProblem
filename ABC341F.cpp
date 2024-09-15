#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
uli f(size_t p, vector<usi> const& w, vector<ui> const& a, vector<uli>& d,
      vector<vector<size_t>>& mp) {
  if (~d[p]) return d[p];
  d[p] = 0;
  vector<uli> dp(w[p]);
  for (size_t i : mp[p])
    for (usi j = w[p] - 1; j >= w[i]; --j)
      dp[j] = max(dp[j], dp[j - w[i]] + f(i, w, a, d, mp));
  return d[p] = dp.back() + 1;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<vector<size_t>> mp(n);
  while (m--) {
    size_t x, y;
    cin >> x >> y;
    --x, --y;
    mp[x].push_back(y), mp[y].push_back(x);
  }

  vector<usi> w(n);
  vector<ui> a(n);
  for (usi& i : w) cin >> i;
  for (ui& i : a) cin >> i;
  vector<uli> d(n, ~0);
  uli ans = 0;
  for (size_t i = 0; i < n; ++i) ans += a[i] * f(i, w, a, d, mp);
  cout << ans;
  return 0;
}