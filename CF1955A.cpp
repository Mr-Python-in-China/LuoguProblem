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
    ui n, a, b;
    cin >> n >> a >> b;
    cout << n / 2 * min(a * 2, b) + (n % 2 == 1 ? a : 0) << '\n';
  }
  return 0;
}