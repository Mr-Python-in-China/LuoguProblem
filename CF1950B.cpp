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
    bool b0 = false;
    for (size_t i = 0; i < n; ++i) {
      for (size_t k = 0; k < 2; ++k) {
        bool b1 = b0;
        for (size_t j = 0; j < n; ++j) {
          cout.put(b1 ? '.' : '#').put(b1 ? '.' : '#');
          b1 = !b1;
        }
        cout.put('\n');
      }
      b0 = !b0;
    }
  }
  return 0;
}