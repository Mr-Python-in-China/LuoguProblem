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
    ui a, b;
    cin >> a >> b;
    cout << ((a % 2 == 0 && b * 2 != a) || (b % 2 == 0 && a * 2 != b) ? "Yes"
                                                                      : "No")
         << '\n';
  }
  return 0;
}