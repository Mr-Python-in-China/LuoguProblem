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
    size_t n;
    cin >> n;
    size_t ans = -1;
    vector<ui> a(n);
    for (ui& i : a) cin >> i;
    ui const d = a.front();
    size_t len = 0;
    for (ui i : a)
      if (i == d)
        ++len;
      else
        ans = min(len, ans), len = 0;
    ans = min(len, ans);
    (ans == n ? cout << "-1" : cout << ans) << '\n';
  }
  return 0;
}