#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    ui c1, c2, c3, d1, d2, d3;
    cin >> c1 >> c2 >> c3 >> d1 >> d2 >> d3;
    if (c1 > d2 || c3 > d1)
      cout.put('C');
    else {
      ui dist = min(d1, c3);
      d1 -= dist, c3 -= dist;
      if (d1 > c2 || d3 > c1)
        cout.put('D');
      else
        cout.put('E');
    }
    cout.put('\n');
  }
  return 0;
}