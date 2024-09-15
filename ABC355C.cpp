#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, t;
  cin >> n >> t;
  vector<size_t> cr(n, n), cw(n, n);
  size_t cx = n, cy = n;
  for (size_t i = 0; i < t; ++i) {
    ui v;
    cin >> v;
    --v;
    size_t x = v / n, y = v % n;
    if (--cr[x] == 0 || --cw[y] == 0 || (x == y && --cx == 0) ||
        (x + y == n - 1 && --cy == 0))
      return cout << i + 1, 0;
  }
  cout << "-1";
  return 0;
}