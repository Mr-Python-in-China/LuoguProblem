#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
const ui P = 100000000;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<ui> a(n);
  for (ui& i : a)
    for (size_t j = 0; j < m; ++j) {
      char c;
      cin >> c;
      i |= (c == '1') << j;
    }
  vector<vector<ui>> f(n, vector<ui>(1u << m));
  for (ui i = 0; i < (1u << m); ++i)
    if ((i & a[0]) == i && !(i & (i << 1u))) f[0][i] = 1;
  for (size_t i = 1; i < n; ++i)
    for (ui j = 0; j < (1u << m); ++j)
      if ((j & a[i]) == j && !(j & (j << 1u)))
        for (size_t k = 0; k < (1u << m); ++k)
          if (!(j & k)) {
            f[i][j] += f[i - 1][k];
            if (f[i][j] >= P) f[i][j] -= P;
          }
  cout << accumulate(f.back().cbegin(), f.back().cend(), uli(0)) % P;
  return 0;
}