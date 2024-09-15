#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli a, b;
  fin >> a >> b;
  if (a < b) swap(a, b);
  {
    uli g = __gcd(a, b);
    a /= g, b /= g;
  }
  uli ans = 1;
  while (b != 1) {
    uli d = a - b;
    uli m = b - 1;
    for (ui i = 2; (uli)i * i <= d; ++i)
      if (d % i == 0) {
        m = min(m, a % i);
        while (d % i == 0) d /= i;
      }
    if (d > 1) m = min(m, a % d), d /= d;
    ans += m, a -= m, b -= m;
    {
      uli g = __gcd(a, b);
      a /= g, b /= g;
    }
  }
  fout << ans;
  return 0;
}