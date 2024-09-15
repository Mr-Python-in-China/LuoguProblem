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
    vector<ui> a(n), b(n);
    for (ui& i : a) cin >> i;
    for (ui& i : b) cin >> i;
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    bool flag = false;
    for (size_t i = 0; i < n; ++i)
      if (a[i] > b[i]) flag = true;
    size_t ans = 0;
    while (flag) {
      flag = false;
      a.insert(a.begin(), 0);
      for (size_t i = 0; i < n; ++i)
        if (a[i] > b[i]) flag = true;
      ++ans;
    }
    cout << ans << '\n';
  }
  return 0;
}