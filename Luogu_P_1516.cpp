#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
pair<li, li> exgcd(li a, li b) {
  if (b == 0) return {1, 0};
  auto r = exgcd(b, a % b);
  return {r.second, r.first - a / b * r.second};
}
template <typename A, typename B> auto mod(A a, B b) {
  auto r = a % b;
  if (r < 0) r += b;
  return r;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui p, q, m, n, l;
  cin >> p >> q >> m >> n >> l;
  int a = int(m) - int(n), b = l, c = int(q) - int(p), gcd = __gcd(a, b);
  if (c % gcd) cout << "Impossible", exit(0);
  pair<li, li> e = exgcd(a, b);
  li x = e.first * c / gcd, y = e.second * c / gcd;
  li dx = b / gcd, dy = a / gcd;
  li minxc = (x - mod(x, dx)) / dx;
  cout << x - minxc * dx;
  return 0;
}