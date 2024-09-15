#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
ui f(ui n, ui k) {
  static unordered_map<ui, ui> ans;
  if (ans[n]) return ans[n];
  if (n <= k || ((n ^ k) & 1)) return ans[n] = 1;
  return ans[n] = f((n + k) / 2, k) + f((n - k) / 2, k);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n, k;
  cin >> n >> k;
  cout << f(n, k);
  return 0;
}