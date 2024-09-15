#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    ui sum = 0;
    for (size_t i = 0; i < n; i++) {
      ui x;
      cin >> x;
      sum += x;
    }
    cout << (sum & 1 ? "NO\n" : "YES\n");
  }
  return 0;
}