#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  while (cin >> n) {
    vector<uli> a(n);
    for (uli& i : a) cin >> i;
    sort(a.begin(), a.end());
    for (size_t i = 1; i < n; ++i) {
      vector<uli> b(n);
      vector<uli> f;
      for (uli& j : b) cin >> j;
      for (uli j : b) {
        for (uli k : a) f.push_back(k + j);
        inplace_merge(f.begin(), f.begin() + n, f.end());
        f.resize(n);
      }
      a = f;
    }
    for (size_t i = 0; i < n; ++i) cout << a[i] << "\n "[i + 1 < n];
  }
  return 0;
}