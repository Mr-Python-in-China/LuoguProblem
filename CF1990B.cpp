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
    size_t n, y, x;
    cin >> n >> x >> y;
    --x, --y;
    if (n == 2) {
      cout << "1 1\n";
      continue;
    }
    vector<bool> b(n);
    b[x] = b[y] = true;
    for (size_t i = x + 1; i < n; ++i) b[i] = ((i - x) & 1) ^ 1;
    for (size_t i = y - 1; i < n; --i) b[i] = ((y - i) & 1) ^ 1;
    for (size_t i = y + 1; i < x; ++i) b[i] = true;
    for (bool i : b) cout << (i ? "1 " : "-1 ");
    cout << '\n';
  }
  return 0;
}