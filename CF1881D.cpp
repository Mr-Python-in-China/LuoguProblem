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
    cin >> n;
    map<ui, size_t> yz;
    for (size_t i = 0; i < n; ++i) {
      ui x;
      cin >> x;
      ui tmp = x;
      for (ui p = 2; tmp > 1 && p * p <= tmp;) {
        if (tmp % p == 0)
          ++yz[p], tmp /= p;
        else
          ++p;
      }
      if (tmp > 1) ++yz[tmp];
    }
    for (pair<ui, size_t> const& i : yz)
      if (i.second % n > 0) {
        cout << "NO\n";
        goto nexturn;
      }
    cout << "YES\n";
  nexturn:;
  }
  return 0;
}