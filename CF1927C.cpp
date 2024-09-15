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
    vector<bool> ac(k), bc(k);
    for (size_t i = 0; i < n; ++i) {
      ui x;
      cin >> x;
      if (--x < k) ac[x] = true;
    }
    for (size_t i = 0; i < m; ++i) {
      ui x;
      cin >> x;
      if (--x < k) bc[x] = true;
    }
    vector<bool> cc(k);
    for (size_t i = 0; i < k; ++i) cc[i] = ac[i] | bc[i];
    if (accumulate(ac.cbegin(), ac.cend(), size_t(0)) < k / 2 ||
        accumulate(bc.cbegin(), bc.cend(), size_t(0)) < k / 2 ||
        accumulate(cc.cbegin(), cc.cend(), size_t(0)) != k) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
  return 0;
}