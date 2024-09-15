#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, q, k;
  cin >> n >> m >> q >> k;
  vector<size_t> h(n), l(m);
  while (q--) {
    char op;
    size_t x;
    cin >> op >> x;
    (++(op == '1' ? h : l)[--x]) %= k;
  }
  size_t ans = n * m;
  unordered_map<size_t, size_t> mp;
  for (size_t& i : l) ++mp[i];
  for (size_t& i : h) ans -= mp[(k - i) % k];
  cout << ans;
  return 0;
}