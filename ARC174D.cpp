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
    uli x;
    cin >> x;
    ++x;
    uli ans = 0;
    uli i = 10;
    for (; i * i < x; i *= 10) ans += i + i / 10 + 1;
    i /= 10;
    if (x > i * i) ans += min(x - i * i, i);
    if (x > (i * 10 - 2) * i * 10) ++ans;
    if (x > (i * 10 - 1) * i * 10) ans += x - (i * 10 - 1) * i * 10;
    cout << ans << '\n';
  }
  return 0;
}