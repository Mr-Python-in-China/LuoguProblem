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
    size_t len = 0;
    bool flag = false;
    uli ans = 0;
    for (size_t i = 0; i < n; ++i) {
      char c;
      cin >> c;
      if (c == '1') {
        if (flag)
          ans += len;
        else
          flag = true;
        len = 0;
      }
      if (flag && c == '0') { ++len; }
    }
    cout << ans << '\n';
  }
  return 0;
}