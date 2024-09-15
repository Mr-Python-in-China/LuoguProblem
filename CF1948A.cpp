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
    if (n & 1)
      cout << "NO\n";
    else {
      cout << "YES\n";
      bool flag = false;
      for (size_t i = 0; i < n; i += 2)
        cout.put('A' + flag).put('A' + flag), flag = !flag;
      cout.put('\n');
    }
  }
  return 0;
}