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
    array<ui, 5> a, p;
    for (ui& i : a) cin >> i;
    for (ui& i : p) cin >> i;
    ui target = max(int(a[0] * 2 + a[1] * 1) - int(a[4] * 2 + a[3] * 1), 0);
    cout << (target / 2 * min<uli>(p[3] * 2, p[4]) +
             target % 2 * min<uli>(p[3], p[4]))
         << '\n';
  }
  return 0;
}