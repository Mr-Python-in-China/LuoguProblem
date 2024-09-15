#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<uli> w(n), l(n), r(n);
  for (uli& i : w) cin >> i;
  for (uli& i : l) cin >> i;
  for (uli& i : r) cin >> i;
  uli ans = 0;
  for (size_t i = 0; i < n; ++i) ans += w[i] - max(l[i], r[i]) * (n - i - 1);
  cout << ans;
  return 0;
}