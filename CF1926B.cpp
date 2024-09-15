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
    size_t miny = n, maxy = 0, cnt = 0;
    for (size_t i = 0; i < n; ++i)
      for (size_t j = 0; j < n; ++j) {
        char c;
        cin >> c;
        if (c == '1') ++cnt, miny = min(miny, j), maxy = max(maxy, j);
      }
    cout << ((maxy - miny + 1) * (maxy - miny + 1) == cnt ? "SQUARE\n"
                                                          : "TRIANGLE\n");
  }
  return 0;
}