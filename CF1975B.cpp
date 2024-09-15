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
    sort(a.begin(), a.end());
    vector<ui> b;
    for (size_t i = 0; i < n; ++i)
      if (a[i] % a.front() != 0) b.emplace_back(a[i]);
    if (b.empty()) {
      cout << "Yes\n";
      continue;
    }
    ui g = b.front();
    for (ui i : b) g = __gcd(i, g);
    for (ui i : b)
      if (g % i == 0) {
        cout << "Yes\n";
        goto out;
      }
    cout << "No\n";
  out:;
  }
  return 0;
}