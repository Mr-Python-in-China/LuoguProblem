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
    li x, a, b;
    cin >> x >> a >> b;
    if (a == 0)
      cout << -b;
    else if (b == 0)
      cout << x;
    else if (a == 1)
      cout << x - (x / b + 1) * b;
    else if ((long double)b / (a - 1) <= x)
      cout << x;
    else {
      while (x >= 0) x = a * x - b;
      cout << x;
    }
    cout.put('\n');
  }
  return 0;
}