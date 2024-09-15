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
    uli k;
    cin >> n >> m >> k;
    set<ui> a;
    set<ui, greater<ui>> b;
    ui ans = 1;
    for (size_t i = 0; i < n; ++i) {
      ui x;
      cin >> x;
      b.insert(x);
      if (b.size() - a.size() == 2) a.insert(*b.rbegin()), b.erase(*b.rbegin());
      auto s = a.cbegin();
      auto t = b.cbegin();
      uli sum = 0;
      for (size_t j = min(a.size(), m); j > 0; --j, ++s, ++t)
        sum += uli(*t - *s) * (*t - *s);
      if (sum > k) ++ans, a.clear(), b.clear(), b.insert(x);
    }
    cout << ans << '\n';
  }
  return 0;
}