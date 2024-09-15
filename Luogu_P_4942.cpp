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
    uli l, r;
    cin >> l >> r;
    cout << (l + r) % 9 * (r - l + 1) % 9 * 5 % 9 << '\n';
  }
  return 0;
}