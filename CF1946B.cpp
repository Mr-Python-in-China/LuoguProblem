#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 1e9 + 7;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<li> f(n);
    f[0] = a[0];
    for (size_t i = 1; i < n; ++i) f[i] = max(f[i - 1], li(0)) + a[i];
    li maxv = 0;
    for (li i : f) maxv = max(maxv, i);
    ui ans = 1;
    while (k--) {
      ans = ans * 2;
      if (ans > P) ans -= P;
    }
    ans = uli(ans - 1) * (maxv % P) % P;
    int x = (li(ans) + accumulate(a.cbegin(), a.cend(), li(0))) % P;
    if (x < 0) x += P;
    cout << x << '\n';
  }
  return 0;
}