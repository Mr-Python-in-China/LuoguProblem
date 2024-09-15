#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int x;
  cin >> x;
  double ans;
  if (x > 400)
    ans = 150 * 0.4463 + (400 - 150) * 0.4663 + (x - 400) * 0.5663;
  else if (x > 150)
    ans = 150 * 0.4463 + (x - 150) * 0.4663;
  else
    ans = x * 0.4463;
  cout << fixed << setprecision(1) << ans;
  return 0;
}