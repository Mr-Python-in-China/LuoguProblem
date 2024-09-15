#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> T abs_minus(T const& a, T const& b) {
  return max(a, b) - min(a, b);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    ui h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;
    if (xa >= xb)
      cout << "Draw\n";
    else if (xb - xa & 1) {
      if (abs_minus(ya, yb) <= 1)
        cout << "Alice\n";
      else {
        ui dis = ya < yb ? w - yb : yb - 1;
        ui step = min(((xb - dis) - (xa + dis) - 1 >> 1) + dis, xb - xa >> 1);
        if (ya < yb ? ya + step >= w - 1 : int(ya) - int(step) <= 2)
          cout << "Alice\n";
        else
          cout << "Draw\n";
      }
    } else {
      ++xa, ya = (ya < yb ? max(ya - 1, 1u) : min(ya + 1, w));
      if (abs_minus(ya, yb) <= 1)
        cout << "Bob\n";
      else {
        ui dis = ya < yb ? w - yb : yb - 1;
        ui step = min(((xb - dis) - (xa + dis) - 1 >> 1) + dis, xb - xa >> 1);
        if (yb < ya ? yb + step >= w - 1 : int(yb) - int(step) <= 2)
          cout << "Bob\n";
        else
          cout << "Draw\n";
      }
    }
  }
  return 0;
}