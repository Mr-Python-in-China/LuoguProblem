#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  uli x, y;
  cin >> n >> x >> y;
  vector<ui> a(n), b(n);
  for (ui &i : a) cin >> i;
  for (ui &i : b) cin >> i;
  cout << min(
      [&a, &x, &n] {
        sort(a.begin(), a.end(), greater<>());
        size_t i = 0;
        uli sum = 0;
        for (; i < n;) {
          sum += a[i++];
          if (sum > x) break;
        }
        return i;
      }(),
      [&b, &y, &n] {
        sort(b.begin(), b.end(), greater<>());
        size_t i = 0;
        uli sum = 0;
        for (; i < n;) {
          sum += b[i++];
          if (sum > y) break;
        }
        return i;
      }());
  return 0;
}