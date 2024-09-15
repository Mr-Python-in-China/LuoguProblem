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
    ui x, y;
    char kk;
    cin >> x >> kk >> y;
    bool flag = false;
    if (x >= 12) flag = true;
    if (x == 0) x = 12;
    if (x > 12) x -= 12;
    cout << (x < 10 ? "0" : "") << x << ':' << (y < 10 ? "0" : "") << y << ' '
         << (flag ? "PM" : "AM") << '\n';
  }
  return 0;
}