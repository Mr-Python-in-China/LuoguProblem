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
    ui x;
    cin >> x;
    cout << (1 << (sizeof(ui) * 8 - __builtin_clz(x) - 1)) << '\n';
  }
  return 0;
}