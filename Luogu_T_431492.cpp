#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  int xmin = numeric_limits<int>::max(), xmax = numeric_limits<int>::min(),
      ymin = numeric_limits<int>::max(), ymax = numeric_limits<int>::min();
  while (n--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    xmin = min({xmin, x1, x2}), xmax = max({xmax, x1, x2}),
    ymin = min({ymin, y1, y2}), ymax = max({ymax, y1, y2});
  }
  cout << li(xmax - xmin) * (ymax - ymin);
  return 0;
}