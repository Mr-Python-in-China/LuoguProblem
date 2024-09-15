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
    for (size_t i = 1; i < n - 1; ++i) {
      if (a[i - 1] * 2 > a[i] || a[i - 1] > a[i + 1]) goto failed;
      a[i] -= a[i - 1] * 2, a[i + 1] -= a[i - 1], a[i - 1] = 0;
    }
    if (accumulate(a.cbegin(), a.cend(), 0)) goto failed;
    cout << "YES\n";
    continue;
  failed:;
    cout << "NO\n";
  }
  return 0;
}