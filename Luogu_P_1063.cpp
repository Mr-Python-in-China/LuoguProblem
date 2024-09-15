#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
ui dp(size_t l, size_t r, vector<ui> const& a) {
  static vector<vector<ui>> ans(a.size(), vector<ui>(a.size(), -1));
  if (ans[l][r] != -1) return ans[l][r];
  ans[l][r] = 0;
  for (size_t mid = l + 1; mid < r; ++mid)
    ans[l][r] =
        max(ans[l][r], dp(l, mid, a) + dp(mid, r, a) + a[l] * a[mid] * a[r]);
  return ans[l][r];
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<ui> a(n << 1);
  for (size_t i = 0; i < n; ++i) cin >> a[i];
  copy(a.begin(), a.begin() + n, a.begin() + n);
#ifdef debug
  for (ui const& i : a) cout << i << ' ';
  cout << '\n';
#endif
  ui ans = 0;
  for (size_t i = 0; i < n; ++i) ans = max(ans, dp(i, i + n, a));
  cout << ans;
  return 0;
}