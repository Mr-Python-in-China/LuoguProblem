#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n, l, t;
  cin >> n >> l >> t;
  --t;
  vector<vector<ui>> f(n + 1, vector<ui>(l + 1));
  f[0][0] = 1;
  for (ui i = 1; i <= n; ++i)
    for (ui j = 1; j <= l; ++j)
      for (ui k = 0; k < i; ++k) f[i][j] += f[k][j - 1];
  ui sum =
      accumulate(f.cbegin(), f.cend(), ui(0), [](ui x, vector<ui> const& a) {
        return x + accumulate(a.cbegin(), a.cend(), ui(0));
      });
  vector<bool> ans(n);
  ui c = 0;
  for (ui i = n; i > 0; --i) {
    ui ns = accumulate(f[i].begin(), f[i].end() - c, ui(0));
    if (t >= sum - ns)
      t -= sum - ns, ++c, ans[i - 1] = true, sum = ns;
    else
      sum -= ns;
  }
  for_each(ans.rbegin(), ans.rend(), [](bool x) { cout << x; });
  return 0;
}