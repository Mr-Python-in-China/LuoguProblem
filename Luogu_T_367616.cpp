#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using uli = unsigned long long int;
const char f[4][2] = {
    { 1,  0},
    { 0,  1},
    {-1,  0},
    { 0, -1}
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  unordered_map<char, size_t> mp;
  vector<vector<char>> a(n, vector<char>(m));
  for (vector<char>& i : a)
    for (char& j : i) cin >> j, ++mp[j];
  size_t ans = 0;
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < m; j++) {
      ans += mp[a[i][j]] - 1;
      for (size_t k = 0; k < 4; k++)
        if (i + f[k][0] < n && j + f[k][1] < m &&
            a[i + f[k][0]][j + f[k][1]] == a[i][j])
          --ans;
    }
  cout << ans;
  return 0;
}