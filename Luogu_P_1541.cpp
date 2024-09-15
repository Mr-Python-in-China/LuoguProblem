#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using dparr = vector<vector<vector<vector<ui>>>>;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  array<size_t, 4> s{};
  for (size_t i = 0; i < m; ++i) {
    size_t x;
    cin >> x;
    ++s[--x];
  }
  vector<vector<vector<vector<ui>>>> f(
      s[0] + 1,
      vector<vector<vector<ui>>>(
          s[1] + 1, vector<vector<ui>>(s[2] + 1, vector<ui>(s[3] + 1))));
  f[0][0][0][0] = a[0];
  for (array<size_t, 4> i{}; i[0] <= s[0]; ++i[0])
    for (i[1] = 0; i[1] <= s[1]; ++i[1])
      for (i[2] = 0; i[2] <= s[2]; ++i[2])
        for (i[3] = 0; i[3] <= s[3]; ++i[3]) {
          size_t p = i[0] * 1 + i[1] * 2 + i[2] * 3 + i[3] * 4;
          ui nx = p >= n ? 0 : a[p];
          ui& nf = f[i[0]][i[1]][i[2]][i[3]];
          if (i[0]) nf = max(nf, f[i[0] - 1][i[1]][i[2]][i[3]] + nx);
          if (i[1]) nf = max(nf, f[i[0]][i[1] - 1][i[2]][i[3]] + nx);
          if (i[2]) nf = max(nf, f[i[0]][i[1]][i[2] - 1][i[3]] + nx);
          if (i[3]) nf = max(nf, f[i[0]][i[1]][i[2]][i[3] - 1] + nx);
        }
  cout << f.back().back().back().back();
  return 0;
}