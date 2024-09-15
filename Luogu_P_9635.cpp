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
    switch (n) {
      case 1: cout << "1"; break;
      case 2: cout << "1 3"; break;
      case 3: cout << "-1"; break;
      case 7: cout << "1 2 4 9 6 7 8"; break;
      default:
        switch (n & 0b11) {
          case 0:
            for (size_t i = 1; i <= n; ++i) cout << i << ' ';
            break;
          case 1:
            for (size_t i = 2; i < n - 1; ++i) cout << i << ' ';
            cout << n << ' ' << n + 1 << ' ' << n + 2;
            break;
          case 2:
            cout << "1 " << n + 1 << ' ';
            for (size_t i = 2; i < n; ++i) cout << i << ' ';
            break;
          case 3:
            cout << "1 2 " << n - 3 << ' ';
            for (size_t i = 4; i < n - 3; ++i) cout << i << ' ';
            for (size_t i = n - 1; i <= n + 2; ++i) cout << i << ' ';
            break;
        }
    }
    cout << '\n';
  }
  return 0;
}