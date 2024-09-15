#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<vector<int>> dil(n + 1, vector<int>(n + 1));
  while (m--) {
    size_t x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    dil[x1 - 1][y1 - 1]++, dil[x1 - 1][y2]--, dil[x2][y1 - 1]--, dil[x2][y2]++;
    // vector<vector<int>> a(n+1,vector<int>(n+1));
    // for (size_t i=0;i<n;i++){
    //     for (size_t j=0;j<n;j++)
    //         cout<<(a[i+1][j+1]=a[i][j+1]+a[i+1][j]-a[i][j]+dil[i][j])<<' ';
    //     cout<<'\n';
    // }
    // cout<<"------------------------\n";
  }
  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++)
      cout << (a[i + 1][j + 1] =
                   a[i][j + 1] + a[i + 1][j] - a[i][j] + dil[i][j])
           << ' ';
    cout << '\n';
  }
  return 0;
}