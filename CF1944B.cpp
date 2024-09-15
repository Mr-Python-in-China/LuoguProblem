#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using uc = unsigned char;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, k;
    cin >> n >> k;
    vector<uc> c1(n), c2(n);
    for (size_t i = 0; i < n; ++i) {
      ui x;
      cin >> x;
      ++c1[--x];
    }
    for (size_t i = 0; i < n; ++i) {
      ui x;
      cin >> x;
      ++c2[--x];
    }
    {
      size_t d = 2 * k;
      for (ui i = 0; i < n; ++i)
        if (c1[i] == 2 && d >= 2) cout << i + 1 << ' ' << i + 1 << ' ', d -= 2;
      for (ui i = 0; i < n; ++i)
        if (c1[i] == 1 && d >= 1) cout << i + 1 << ' ', --d;
      cout << '\n';
    }
    {
      size_t d = 2 * k;
      for (ui i = 0; i < n; ++i)
        if (c2[i] == 2 && d >= 2) cout << i + 1 << ' ' << i + 1 << ' ', d -= 2;
      for (ui i = 0; i < n; ++i)
        if (c2[i] == 1 && d >= 1) cout << i + 1 << ' ', --d;
      cout << '\n';
    }
  }
  return 0;
}