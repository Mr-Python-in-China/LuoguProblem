#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
pair<li, li> exgcd(li a, li b) {
  if (b == 0) return {1, 0};
  pair<li, li> t = exgcd(b, a % b);
  return {t.second, t.first - a / b * t.second};
}
template <typename A, typename B>
ostream& operator<<(ostream& out, pair<A, B> const& v) {
  return out << v.first << ' ' << v.second;
}
template <typename A, typename B> auto notmod(A a, B b) {
  auto res = a % b;
  if (res <= 0) res += b;
  return res;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    ui a, b, c;
    cin >> a >> b >> c;
    if (c % __gcd(a, b) != 0)
      cout << "-1\n";
    else {
      pair<li, li> e = exgcd(a, b);
      ui gcd = __gcd(a, b);
      e.first *= c / gcd, e.second *= c / gcd;
      li x = e.first, y = e.second;
      ui dx = b / gcd, dy = a / gcd;
      li step_xbm = (x - notmod(x, dx)) / dx,
         step_ybm = (y - notmod(y, dy)) / dy;
      if (step_xbm * dy + y <= 0 || step_ybm * dx + x <= 0)
        cout << notmod(x, dx) << ' ' << notmod(y, dy) << '\n';
      else
        cout << (step_ybm * dx + x - notmod(x, dx)) / dx + 1 << ' '
             << notmod(x, dx) << ' ' << notmod(y, dy) << ' '
             << step_ybm * dx + x << ' ' << step_xbm * dy + y << '\n';
    }
  }
  return 0;
}