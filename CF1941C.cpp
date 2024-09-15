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
    string s;
    size_t n;
    cin >> n >> s;
    ui ans = 0;
    for (string::const_iterator it = s.cbegin(); it < s.cend(); ++it)
      if ((it - s.cbegin() >= 2 && equal(it - 2, it + 1, "map")) ||
          (s.end() - it >= 3 && equal(it, it + 3, "pie")))
        ++ans;
    cout << ans << '\n';
  }
  return 0;
}