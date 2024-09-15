#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
pair<int, int> exgcd(int a, int b) {
  if (b == 0) return {1, 0};
  pair<int, int> t = exgcd(b, a % b);
  return {t.second, t.first - a / b * t.second};
}
template <typename A, typename B> auto notmod(A a, B b) {
  auto res = a % b;
  if (res <= 0) res += b;
  return res;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n;
  fin >> n;
  for (ui a = 1; a * a <= n; ++a)
    if (n % a == 0) {
      ui b = n / a;
      ui g = __gcd(a, b);
      if ((n - 1) % g) continue;
      pair<int, int> e = exgcd(a, b);
      li x = (li)e.first * (n - 1) / g, y = (li)e.second * (n - 1) / g;
      ui dx = b / g, dy = a / g;
      li step_xbm = (x - notmod(x, dx)) / dx;
      if (step_xbm * dy + y > 0) {
        ui ansx = notmod(x, dx);
        fout << "YES\n2\n"
             << ansx << ' ' << b << '\n'
             << step_xbm * dy + y << ' ' << a;
        return 0;
      }
    }
  fout << "NO";
  return 0;
}