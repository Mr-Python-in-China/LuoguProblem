#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    size_t cv = m, ci = m, ck = m, ca = m;
    for (vector<char>& i : a)
      for (char& j : i) cin >> j;
    for (size_t i = 0; i < m; i++)
      for (size_t j = 0; j < n; j++)
        if (a[j][i] == 'v') {
          cv = i;
          goto out1;
        }
  out1:;
    for (size_t i = cv + 1; i < m; i++)
      for (size_t j = 0; j < n; j++)
        if (a[j][i] == 'i') {
          ci = i;
          goto out2;
        }
  out2:;
    for (size_t i = ci + 1; i < m; i++)
      for (size_t j = 0; j < n; j++)
        if (a[j][i] == 'k') {
          ck = i;
          goto out3;
        }
  out3:;
    for (size_t i = ck + 1; i < m; i++)
      for (size_t j = 0; j < n; j++)
        if (a[j][i] == 'a') {
          ca = i;
          goto out4;
        }
  out4:;
    cout << (cv != m && ci != m && ck != m && ca != m ? "YES\n" : "NO\n");
  }
  return 0;
}