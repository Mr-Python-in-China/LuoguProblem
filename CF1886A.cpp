#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int a = n - 3, b = n - 5;
    if (a > 2 && a % 3)
      cout << "YES\n1 2 " << a << '\n';
    else if (b != 1 && b != 4 && b > 0 && b % 3)
      cout << "YES\n1 4 " << b << '\n';
    else
      cout << "NO\n";
  }
  return 0;
}