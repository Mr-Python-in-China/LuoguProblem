#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
ui f(int x) {
  ui i, ans = 0;
  for (i = 1; int(i * i) < x; ++i)
    if (x % i == 0) (i % 2 == 0 ? ++ans : 0), (x / i % 2 == 0 ? ++ans : 0);
  if (int(i * i) == x) (i % 2 == 0 ? ++ans : 0);
  return ans;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    ui x, n;
    cin >> x >> n;
    --x, --n;
    // case 1: x%(2k-2)==n => (x-n)%(2k-2)==0
    // case 2: x%(2k-2)==-n => (x+n)%(2k-2)==0
    unordered_set<ui> s;
    if (x >= n) {
      ui i;
      for (i = 1; i * i < x - n; ++i)
        if ((x - n) % i == 0) s.insert(i), s.insert((x - n) / i);
      if (i * i == x - n) s.insert(i);
    }
    {
      ui i;
      for (i = 1; i * i < x + n; ++i)
        if ((x + n) % i == 0) s.insert(i), s.insert((x + n) / i);
      if (i * i == x + n) s.insert(i);
    }
    size_t ans = 0;
    for (ui const i : s)
      if (i % 2 == 0 && (i + 2) / 2 > n) ++ans;
    cout << ans << '\n';
  }
  return 0;
}