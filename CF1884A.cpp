#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
ui f(ui x) {
  ui res = 0;
  while (x) res += x % 10, x /= 10;
  return res;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    ui x, k;
    cin >> x >> k;
    for (; f(x) % k; ++x);
    cout << x << '\n';
  }
  return 0;
}