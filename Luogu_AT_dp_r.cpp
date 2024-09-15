#include <bits/stdc++.h>
using namespace std;
const int N = 105, mod = 1e9 + 7;
long long f[N][N], n, k, ans;
struct matrix {
  long long a[N][N];
  matrix operator*(matrix x) const {
    matrix c;
    memset(c.a, 0, sizeof c.a);
    for (int i = 1; i <= n; i++)
      for (int k = 1; k <= n; k++)
        for (int j = 1; j <= n; j++)
          c.a[i][j] += a[i][k] * x.a[k][j], c.a[i][j] %= mod;
    return c;
  }
} dis, res;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> dis.a[i][j];
  for (int i = 1; i <= n; i++) res.a[i][i] = 1;
  for (; k; k >>= 1, dis = dis * dis)
    if (k & 1) res = res * dis;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) ans += res.a[i][j], ans %= mod;
  cout << ans << '\n';
  return 0;
}