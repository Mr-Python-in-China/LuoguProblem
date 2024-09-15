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
    vector<ui> a(n);
    for (ui& i : a) cin >> i;
    sort(a.begin(), a.end());
    size_t mid = (n - 1) / 2;
    ui d = a[mid];
    ui ans = 0;
    for (size_t i = mid; i < n; ++i)
      if (a[i] == d) ++a[i], ++ans;
    cout << ans << '\n';
  }
  return 0;
}