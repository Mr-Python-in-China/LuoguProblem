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
    size_t n, m;
    ui k;
    cin >> n >> m >> k;
    vector<ui> a(n), b(m);
    for (ui& i : a) cin >> i;
    for (ui& i : b) cin >> i;
    ui ans = 0;
    for (ui i : a)
      for (ui j : b)
        if (i + j <= k) ++ans;
    cout << ans << '\n';
  }
  return 0;
}