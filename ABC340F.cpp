#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using lli = __int128_t;
pair<lli, lli> exgcd(lli a, lli b) {
  if (b == 0) return {1, 0};
  pair<lli, lli> t = exgcd(b, a % b);
  return {t.second, t.first - a / b * t.second};
}
ostream& operator<<(ostream& out, lli x) {
  if (x < 0) cout.put('-'), x = -x;
  if (x / 10) out << x / 10;
  return out.put(x % 10 + '0');
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  li x, y;
  cin >> x >> y;
  if (y == 0) {
    if (abs(x) == 1)
      cout << "0 2";
    else if (abs(x) == 2)
      cout << "0 1";
    else
      cout << "-1";
  } else if (x == 0) {
    if (abs(y) == 1)
      cout << "2 0";
    else if (abs(y) == 2)
      cout << "1 0";
    else
      cout << "-1";
  } else {
    lli a = -y, b = x;
    lli c = -2 * b;
    a *= x, b *= x;  // ax+by==c
    lli g = __gcd(a, b);
    if (c % g != 0)
      cout << "-1";
    else {
      pair<lli, lli> ans = exgcd(a, b);
      cout << (ans.first *= c / g) << ' ' << (ans.second *= c / g);
    }
  }
  return 0;
}