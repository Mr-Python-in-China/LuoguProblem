#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli a, b, c, d;
  {
    int w, x, y, z;
    cin >> w >> x >> y >> z;
    b = w + 1e9, a = x + 1e9, d = y + 1e9, c = z + 1e9;
  }
  cout << ((d / 4 - (b + 3) / 4) * 4 +
           (b % 4 == 0   ? 0
            : b % 4 == 1 ? 2
            : b % 4 == 2 ? 1
            : b % 4 == 3 ? 1
                         : throw) +
           (d % 4 == 0   ? 0
            : d % 4 == 1 ? 2
            : d % 4 == 2 ? 3
            : d % 4 == 3 ? 3
                         : throw)) *
                  ((c - a) / 2 + ((c - a) % 2 == 1 ? a % 2 == 0 ? 1 : 0 : 0)) +
              ((d / 4 - (b + 3) / 4) * 4 +
               (b % 4 == 0   ? 0
                : b % 4 == 1 ? 3
                : b % 4 == 2 ? 1
                : b % 4 == 3 ? 0
                             : throw) +
               (d % 4 == 0   ? 0
                : d % 4 == 1 ? 1
                : d % 4 == 2 ? 3
                : d % 4 == 3 ? 4
                             : throw)) *
                  ((c - a) -
                   ((c - a) / 2 + ((c - a) % 2 == 1 ? a % 2 == 0 ? 1 : 0 : 0)));
  return 0;
}