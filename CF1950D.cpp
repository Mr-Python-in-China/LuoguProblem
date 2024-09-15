#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
ui bit_to_digit(ui x) { return x ? bit_to_digit(x >> 1) * 10 + (x & 1) : 0; }
bool dfs(ui now, ui lst) {
  if (now == 1) return true;
  for (ui i = lst, t = bit_to_digit(i); t <= now; t = bit_to_digit(++i))
    if (now % t == 0 && dfs(now / t, i)) return true;
  return false;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    ui x;
    cin >> x;
    cout << (x == 1 || dfs(x, 2) ? "YES\n" : "NO\n");
  }
  return 0;
}