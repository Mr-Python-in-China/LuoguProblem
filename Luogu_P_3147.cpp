#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<usi> a(n);
  array<vector<ui>, 60> f;
  f.fill(vector<ui>(n + 1, -1));
  for (size_t i = 0; i < n; ++i) cin >> a[i], f[a[i]][i] = i + 1;
  for (usi j = 1; j < 60; ++j)
    for (size_t i = 0; i < n; ++i) {
      if (!~f[j][i] && ~f[j - 1][i]) f[j][i] = f[j - 1][f[j - 1][i]];
#ifdef debug
      if (i == 0) cerr << j << endl;
#endif
    }
  usi ans = 0;
  for (usi j = 0; j < 60; ++j)
    for (size_t i = 0; i < n; ++i)
      if (~f[j][i]) ans = max(j, ans);
  cout << ans;
  return 0;
}