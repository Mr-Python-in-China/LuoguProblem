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
    ui a, b, c;
    cin >> a >> b >> c;
    cout << (a < b && b > c   ? "PEAK"
             : a < b && b < c ? "STAIR"
                              : "NONE")
         << '\n';
  }
  return 0;
}