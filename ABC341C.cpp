#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t h, w, n;
  cin >> h >> w >> n;
  vector<char> f(n);
  for (char& i : f) cin >> i;
  vector<vector<bool>> mp(h, vector<bool>(w));
  for (vector<bool>& i : mp)
    for (vector<bool>::reference j : i) {
      char c;
      cin >> c;
      j = c == '.';
    }
  size_t ans = 0;
  for (size_t i = 0; i < h; ++i)
    for (size_t j = 0; j < w; ++j)
      if (mp[i][j]) {
        size_t x = i, y = j;
        for (char k : f) {
          x += k == 'L'   ? 0
               : k == 'U' ? -1
               : k == 'R' ? 0
               : k == 'D' ? 1
                          : throw,
              y += k == 'L'   ? -1
                   : k == 'U' ? 0
                   : k == 'R' ? 1
                   : k == 'D' ? 0
                              : throw;
          if (!(x < h && y < w && mp[x][y])) goto oops;
        }
        ++ans;
      oops:;
      }
  cout << ans;
  return 0;
}