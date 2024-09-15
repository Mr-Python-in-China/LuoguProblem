#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using uc = unsigned char;
uli& xorbit(uli& x, uc p) { return x = x ^ (1ull << p); }
uli getbit(uli x, uc p) { return x & (1ull << p); }
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli a, b, c;
  cin >> a >> b >> c;
  ui ta = a, tb = b;
  uli x = 0, y = 0;
  for (size_t i = 0; i < 60; ++i)
    if (getbit(c, i)) {
      xorbit(a > b ? (--a, x) : (--b, y), i);
      if (!~a || !~b) return cout << "-1", 0;
    }
  if (a != b) return cout << "-1", 0;
  for (size_t i = 0; i < 60; ++i)
    if (!getbit(c, i) && a && b) xorbit(x, i), xorbit(y, i), --a, --b;
  if (a) return cout << "-1", 0;
  // if ((x^y)==c&&__builtin_popcountl(x)==ta&&__builtin_popcountl(y)==tb)
  cout << x << ' ' << y;
  // else cout<<"-1";
  return 0;
}