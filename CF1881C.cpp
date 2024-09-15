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
    vector<vector<char>> a(n, vector<char>(n));
    for (vector<char>& i : a)
      for (char& j : i) cin >> j;
    size_t d = n >> 1;
    uli ans = 0;
    for (size_t i1 = 0; i1 < d; ++i1)
      for (size_t j1 = 0; j1 < d; ++j1) {
        size_t i2 = j1, j2 = n - i1 - 1, i3 = j2, j3 = n - i2 - 1, i4 = j3,
               j4 = n - i3 - 1;
        assert(i1 == j4 && j1 == n - i4 - 1);
        char c1 = a[i1][j1], c2 = a[i2][j2], c3 = a[i3][j3], c4 = a[i4][j4],
             maxc = max({c1, c2, c3, c4});
        ans += maxc - c1 + maxc - c2 + maxc - c3 + maxc - c4;
      }
    cout << ans << '\n';
  }
  return 0;
}