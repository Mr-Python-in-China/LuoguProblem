#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  ui a = 0, b = 0;
  while (n--) {
    ui x, y;
    cin >> x >> y;
    a += x, b += y;
  }
  cout << (a > b ? "Takahashi" : a == b ? "Draw" : "Aoki");
  return 0;
}