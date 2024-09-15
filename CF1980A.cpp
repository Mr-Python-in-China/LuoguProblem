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
    size_t n, m;
    cin >> n >> m;
    array<size_t, 7> cnt = {};
    for (size_t i = 0; i < n; ++i) {
      char c;
      cin >> c;
      ++cnt[c - 'A'];
    }
    size_t ans = 0;
    for (size_t i : cnt)
      if (i < m) ans += m - i;
    cout << ans << '\n';
  }
  return 0;
}