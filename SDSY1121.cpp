#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<vector<ui>> dis(n, vector<ui>(n));
  for (vector<ui>& i : dis)
    for (ui& j : i) cin >> j;
  vector<vector<ui>> f(1 << n, vector<ui>(n, numeric_limits<ui>::max() / 2));
  f[1 << 0][0] = 0;
  for (ui i = 0; i < (1u << n); ++i)
    if (__builtin_popcount(i) > 1)
      for (size_t j = 0; j < n; ++j)
        if (i & (1u << j))
          for (size_t k = 0; k < n; ++k)
            if ((j ^ k) && (i & (1u << k)))
              f[i][j] = min(f[i][j], f[i ^ (1u << j)][k] + dis[k][j]);
  cout << f.back()[n - 1];
  return 0;
}