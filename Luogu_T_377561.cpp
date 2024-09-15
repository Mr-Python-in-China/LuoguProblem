#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
#ifndef debug
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#endif
  size_t T;
  cin >> T;
  while (T--) {
    uli n, a, b, c, e, f, g;
    cin >> n >> a >> b >> c >> e >> f >> g;
    uli ans = 0;
    if (a * 1e12 + b * 1e6 + c > e * 1e12 + f * 1e6 + g)
      swap(a, e), swap(b, f), swap(c, g),
          cout << ((n * (10 * n - 7) * (n + 1)) / 6) -
                      (((e * (10 * e - 7) * (e + 1)) / 6 + (f * (5 * f - 4)) +
                        g) -
                       ((a * (10 * a - 7) * (a + 1)) / 6 + (b * (5 * b - 4)) +
                        c))
               << '\n';
    else
      cout << ((e * (10 * e - 7) * (e + 1)) / 6 + (f * (5 * f - 4)) + g) -
                  ((a * (10 * a - 7) * (a + 1)) / 6 + (b * (5 * b - 4)) + c)
           << '\n';
  }
  return 0;
}