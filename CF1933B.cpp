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
    size_t n;
    cin >> n;
    ui sum = 0;
    bool flag = false;
    for (size_t i = 0; i < n; ++i) {
      ui x;
      cin >> x;
      sum += x;
      if (x % 3 == 1) flag = true;
    }
    if (sum % 3 == 0)
      cout << "0\n";
    else if ((sum % 3 == 1 && flag) || sum % 3 == 2)
      cout << "1\n";
    else
      cout << "2\n";
  }
  return 0;
}