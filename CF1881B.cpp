#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
bool equ3(ui a, ui b, ui c) { return a == b && b == c; }
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    ui a, b, c;
    cin >> a >> b >> c;
    cout << (equ3(a, b, c) || (a % 2 == 0 && equ3(a / 2, b, c)) ||
                     (b % 2 == 0 && equ3(a, b / 2, c)) ||
                     (c % 2 == 0 && equ3(a, b, c / 2)) ||
                     (a % 3 == 0 && equ3(a / 3, b, c)) ||
                     (b % 3 == 0 && equ3(a, b / 3, c)) ||
                     (c % 3 == 0 && equ3(a, b, c / 3)) ||
                     (a % 4 == 0 && equ3(a / 4, b, c)) ||
                     (b % 4 == 0 && equ3(a, b / 4, c)) ||
                     (c % 4 == 0 && equ3(a, b, c / 4)) ||
                     (a % 2 == 0 && b % 3 == 0 && equ3(a / 2, b / 3, c)) ||
                     (a % 2 == 0 && c % 3 == 0 && equ3(a / 2, b, c / 3)) ||
                     (b % 2 == 0 && a % 3 == 0 && equ3(a / 3, b / 2, c)) ||
                     (b % 2 == 0 && c % 3 == 0 && equ3(a, b / 2, c / 3)) ||
                     (c % 2 == 0 && a % 3 == 0 && equ3(a / 3, b, c / 2)) ||
                     (c % 2 == 0 && b % 3 == 0 && equ3(a, b / 3, c / 2)) ||
                     (a % 2 == 0 && b % 2 == 0 && equ3(a / 2, b / 2, c)) ||
                     (a % 2 == 0 && c % 2 == 0 && equ3(a / 2, b, c / 2)) ||
                     (b % 2 == 0 && c % 2 == 0 && equ3(a, b / 2, c / 2))
                 ? "YES\n"
                 : "NO\n");
  }
  return 0;
}