#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using ld = long double;
ld f(uli n, unsigned char a, ui x, ui y) {
  static unordered_map<uli, ld> mem;
  auto g = mem.emplace(n, 0);
  if (!g.second) return g.first->second;
  if (n == 0) return 0;
  ld ans1 = f(n / a, a, x, y) + x, ans2 = (ld)y * 6;
  for (unsigned char i = 2; i <= 6; ++i) ans2 += f(n / i, a, x, y);
  return g.first->second = min(ans1, ans2 / 5);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli n;
  ui a, x, y;
  cin >> n >> a >> x >> y;
  cout << fixed << setprecision(15) << f(n, a, x, y);
  return 0;
}