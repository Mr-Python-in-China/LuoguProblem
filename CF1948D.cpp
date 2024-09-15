#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
bool eq(char a, char b) { return a == b || a == '?' || b == '?'; }
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    string t;
    cin >> t;
    size_t ans = 0;
    for (size_t i = 0; i < t.size(); ++i) {
      size_t d = 0;
      for (size_t j = i; j < t.size(); ++j) {
        if (eq(t[j], t[j - i]))
          ++d;
        else
          d = 0;
        if (i == d) ans = max(ans, d * 2);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}