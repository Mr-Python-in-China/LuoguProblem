#include <bits/stdc++.h>
using namespace std;
using si = short int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<vector<short int>> a(n, vector<short int>(n));
  for (vector<short int>& i : a)
    for (short int& j : i) cin >> j;
  vector<vector<int>> sum(n + 1, vector<int>(n + 1));
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < n; j++)
      sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + a[i][j];
  int ans = -0x7fffffff;
  // for (size_t i=0;i<=n;i++){
  //     for (size_t j=0;j<=n;j++) cout<<sum[i][j]<<' ';
  //     cout<<'\n';
  // }
  // cout<<flush;
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < n; j++)
      for (size_t k = i + 1; k <= n; k++)
        for (size_t l = j + 1; l <= n; l++)
          ans = max(ans, sum[k][l] + sum[i][j] - sum[i][l] - sum[k][j]);
  cout << ans;
  return 0;
}