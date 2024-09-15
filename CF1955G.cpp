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
    cin >> n >> m;
    vector<vector<ui>> a(n, vector<ui>(m));
    for (vector<ui>& i : a)
      for (ui& j : i) cin >> j;
    vector<vector<set<ui>>> f(n, vector<set<ui>>(m));
    f[0][0].insert(a[0][0]);
    for (size_t i = 1; i < n; ++i)
      for (ui k : f[i - 1][0]) f[i][0].insert(__gcd(k, a[i][0]));
    for (size_t j = 1; j < m; ++j)
      for (ui k : f[0][j - 1]) f[0][j].insert(__gcd(k, a[0][j]));
    for (size_t i = 1; i < n; ++i)
      for (size_t j = 1; j < m; ++j) {
        for (ui k : f[i][j - 1]) f[i][j].insert(__gcd(k, a[i][j]));
        for (ui k : f[i - 1][j]) f[i][j].insert(__gcd(k, a[i][j]));
      }
    cout << *f.back().back().rbegin() << '\n';
  }
  return 0;
}