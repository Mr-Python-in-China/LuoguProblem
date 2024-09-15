#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, r;
  cout << fixed << setprecision(6);
  for (size_t T = 1; cin >> n >> r && n; ++T) {
    vector<double> p(n);
    for (double &i : p) cin >> i;
    vector<double> ans(n);
    double c = 0;
    for (ui i = 0; i < (1 << n); ++i)
      if (__builtin_popcount(i) == r) {
        double d = 1;
        for (size_t j = 0; j < n; ++j) d *= i & (1 << j) ? p[j] : 1 - p[j];
        c += d;
        for (size_t j = 0; j < n; ++j)
          if (i & (1 << j)) ans[j] += d;
      }

    cout << "Case " << T << ":\n";
    for (double i : ans) cout << i / c << '\n';
  }
  return 0;
}