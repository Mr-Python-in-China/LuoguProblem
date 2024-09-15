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
    ui n, k;
    cin >> n >> k;
    --k;
    for (ui i = 1;; i *= 2) {
      ui c = (n + i) / (i * 2);
      if (k < c) {
        cout << k * i * 2 + i << '\n';
        break;
      }
      k -= c;
    }
  }
  return 0;
}