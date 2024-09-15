#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    usi a, b, c, d;
    cin >> a >> b >> c >> d;
    ui ans = 0;
    if (a == b && b == c && a % 2 == 1) ++ans;
    a -= a % 2, b -= b % 2, c -= c % 2, d -= d % 2;
    ++ans;
    while (d) d -= 2, ++ans;
    while (c) c -= 2, ++ans;
    while (b) b -= 2, ++ans;
    while (a) a -= 2, ++ans;
    cout << --ans << '\n';
  }
  return 0;
}