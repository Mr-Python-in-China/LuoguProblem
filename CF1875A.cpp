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
    uli a, b, ans = 0;
    size_t n;
    cin >> a >> b >> n;
    while (n--) {
      uli x;
      cin >> x;
      ans += b - 1;
      b = min(x + 1, a);
    }
    cout << (ans += b) << '\n';
  }
  return 0;
}