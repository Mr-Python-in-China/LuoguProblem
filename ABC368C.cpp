#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  fin >> n;
  uli ans = 0;
  while (n--) {
    ui x;
    fin >> x;
    ui a = 3 - ans % 3;
    if (x >= a + 2) {
      x -= a + 2, ans += a;
      ui b = x / 5;
      x -= b * 5, ans += b * 3;
      ui c = x == 0 ? 0 : x == 1 ? 1 : x == 2 ? 2 : 3;
      ans += c;
    } else {
      while (x > (++ans % 3 ? 1 : 3)) x -= (ans % 3 ? 1 : 3);
    }
  }
  fout << ans;
  return 0;
}