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
    for (ui &i : a) cin >> i;
    for (size_t i = 0; i < n; ++i) {
      if (is_sorted(a.begin(), a.end())) {
        cout << "Yes\n";
        goto out;
      }
      rotate(a.begin(), next(a.begin()), a.end());
    }
    cout << "No\n";
  out:;
  }
  return 0;
}