#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<vector<bool>> a(n, vector<bool>(m));
  for (vector<bool>& i : a)
    for (vector<bool>::reference j : i) {
      char c;
      cin >> c;
      j = c == 'F';
    }
  vector<vector<usi>> su(n, vector<usi>(m)), sl(n, vector<usi>(m)),
      sr(n, vector<usi>(m)), msl(n, vector<usi>(m)), msr(n, vector<usi>(m));
  for (size_t i = 0; i < n; ++i) {
    sl[i][0] = a[i][0];
    for (size_t j = 1; j < m; ++j) sl[i][j] = a[i][j] ? sl[i][j - 1] + 1 : 0;
  }
  for (size_t i = 0; i < n; ++i) {
    sr[i][m - 1] = a[i][m - 1];
    for (size_t j = m - 2; j < m; --j)
      sr[i][j] = a[i][j] ? sr[i][j + 1] + 1 : 0;
  }
  for (size_t j = 0; j < m; ++j) su[0][j] = a[0][j];
  for (size_t i = 1; i < n; ++i)
    for (size_t j = 0; j < m; ++j) su[i][j] = a[i][j] ? su[i - 1][j] + 1 : 0;
  for (size_t j = 0; j < m; ++j) msl[0][j] = sl[0][j], msr[0][j] = sr[0][j];
  for (size_t i = 1; i < n; ++i)
    for (size_t j = 0; j < m; ++j)
      msl[i][j] = min(a[i - 1][j] ? msl[i - 1][j] : numeric_limits<usi>::max(),
                      sl[i][j]),
      msr[i][j] = min(a[i - 1][j] ? msr[i - 1][j] : numeric_limits<usi>::max(),
                      sr[i][j]);
  ui ans = 0;
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < m; ++j)
      ans = max(ans, su[i][j] * ui(msl[i][j] + msr[i][j] - 1));
  cout << ans * 3;
  return 0;
}