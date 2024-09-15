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
    uli k;
    cin >> n >> k;
    vector<uli> cnt(n);
    for (size_t i = 0; i < n; ++i) cin >> cnt[i];
    uli l = 0, r = 1e14;
    auto check = [&](uli x) {
      uli d = 0;
      for (uli const& i : cnt)
        if (i < x) d += x - i;
      return d;
    };
    while (l < r) {
      uli mid = (l + r + 1) / 2;
      check(mid) <= k ? l = mid : r = mid - 1;
    }
    for (uli& i : cnt)
      if (i < l) k -= l - i, i = l;
    sort(cnt.begin(), cnt.end());
    for (auto it = cnt.begin(); k; ++it) ++*it, --k;
    sort(cnt.begin(), cnt.end());
    size_t d = cnt.end() - find_if_not(cnt.begin(), cnt.end(), [&cnt](uli x) {
                 return cnt.front() == x;
               });
    cout << cnt.front() * n + d - (n - 1) << '\n';
  }
  return 0;
}