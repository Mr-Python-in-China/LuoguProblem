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
  array<int, 2000 * 400 + 1> f;
  f.fill(numeric_limits<int>::min() / 2);
  f[0 + 2000 * 400 / 2] = 0;
  for (size_t i = 0; i < n; ++i) {
    array<int, 2000 * 400 + 1> ff{};
    ff.fill(numeric_limits<int>::min() / 2);
    int iq, eq;
    cin >> iq >> eq;
    for (int i = max(iq, 0) - 2000 * 400 / 2;
         i <= 2000 * 400 / 2 && i - iq <= 2000 * 400 / 2; ++i)
      ff.at(i + 2000 * 400 / 2) =
          max(f.at(i + 2000 * 400 / 2), f.at(i - iq + 2000 * 400 / 2) + eq);
    f = ff;
  }
  int ans = 0;
  for (int i = 0; i <= 2000 * 400 / 2; ++i)
    if (f.at(i + 2000 * 400 / 2) >= 0)
      ans = max(ans, f.at(i + 2000 * 400 / 2) + i);
  cout << ans;
  return 0;
}