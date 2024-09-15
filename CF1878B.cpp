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
    ui ls1 = 1, ls2 = 3;
    cout << ls1 << ' ' << ls2 << ' ';
    for (size_t i = 2; i < n; ++i) {
      ui ls3 = ls2 + 1;
      for (; ls3 * 3 % (ls1 + ls2) == 0; ++ls3);
      cout << ls3 << ' ';
      ls1 = ls2, ls2 = ls3;
    }
    cout << '\n';
  }
  return 0;
}