#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n, m;
  cin >> n >> m;
  vector<unsigned short int> s(n);
  for (auto &i : s)
    for (ui j = 0; j < m; ++j) {
      char c;
      cin >> c;
      (i <<= 1) |= c == 'o';
    }
  ui ans = numeric_limits<ui>::max();
  for (ui i = 0; i < (1 << n); ++i) {
    unsigned short int t = 0;
    for (size_t j = 0; j < n; ++j)
      if ((i >> j) & 1) t |= s[j];
    if (t == (1 << m) - 1) ans = min<ui>(ans, __builtin_popcount(i));
  }
  cout << ans;
  return 0;
}