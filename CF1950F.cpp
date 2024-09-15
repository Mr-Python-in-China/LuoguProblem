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
    ui a, b, c;
    cin >> a >> b >> c;
    if (a + 1 != c) {
      cout << "-1\n";
      continue;
    }
    ui d = floor(log2(c)), f = 1 << d;
    ui oth = c - f;
    ui ans = d + (oth * 2 + b + c - 1) / c;
    cout << ans << '\n';
  }
  return 0;
}