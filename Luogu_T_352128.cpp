#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int a, b, c;
  cin >> a >> b >> c;
  cout << (a + b + c <= 100 && b % 5 == 0 && c % 7 == 0 && a - b > b - c
               ? "Yes"
               : "No");
  return 0;
}