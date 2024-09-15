#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
struct type {
  bool r, b, w;
  type(void): r(1), b(1), w(1) {}
  size_t change(char color) {
#ifdef debug
    cout << r << b << w << ' ';
#endif
    if (r && b && w) {
      if (color == 'R') return b = w = 0, 2;
      if (color == 'B') return w = 0, 1;
      if (color == 'W') return 0;
    }
    if (!r && b && w) {
      if (color == 'R') return b = w = 0, r = 1, 3;
      if (color == 'B') return w = 0, 1;
      if (color == 'W') return 0;
    }
    if (r && !b && w) {
      if (color == 'R') return w = 0, 1;
      if (color == 'B') return w = 0, b = 1, 2;
      if (color == 'W') return 0;
    }
    if (r && b && !w) {
      if (color == 'R') return b = 0, 1;
      if (color == 'B') return 0;
      if (color == 'W') return w = 1, 1;
    }
    if (!r && !b && w) {
      if (color == 'R') return r = 1, w = 0, 2;
      if (color == 'B') return w = 0, b = 1, 2;
      if (color == 'W') return 0;
    }
    if (!r && b && !w) {
      if (color == 'R') return b = 0, r = 1, 2;
      if (color == 'B') return b = 1, 1;
      if (color == 'W') return w = 1, 1;
    }
    if (r && !b && !w) {
      if (color == 'R') return 0;
      if (color == 'B') return b = 1, 1;
      if (color == 'W') return w = 1, 1;
    }
    if (!r && !b && !w) {
      if (color == 'R') return r = 1, 1;
      if (color == 'B') return b = 1, 1;
      if (color == 'W') return w = 1, 1;
    }
    return -1;
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  size_t ans = 0;
  type t;
  while (n--) {
    char c;
    cin >> c;
    ans += t.change(c);
#ifdef debug
    cout << ans << '\n';
#endif
  }
  cout << ans;
  return 0;
}