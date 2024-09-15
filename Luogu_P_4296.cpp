#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n;
  cin >> n;
  if (n == 1) cout << "None", exit(0);
  set<ui> ans;
  cout << "1\n";
  for (ui a = 1; a * a <= n; ++a)
    if (n % a == 0) {
      ui b = n / a;
      for (ui x = b + 1; x <= n; x += b)
        if ((x + 1) % a == 0) ans.insert(x);
      for (ui x = b - 1; x <= n; x += b)
        if ((x - 1) % a == 0) ans.insert(x);
    }
  for (ui i : ans) cout << i << '\n';
  return 0;
}