#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using usi = unsigned short int;
using si = short int;
int main(void) {
  // ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
  usi n, m;
  cin >> n >> m;
  vector<vector<ui>> a(n, vector<ui>(n));
  {
    ui c = 0;
    for (usi i = 0; i < n; i++)
      for (usi j = 0; j < n; j++) a[i][j] = ++c;
  }
  while (m--) {
    // for (vector<vector<ui>>::reference i:a){
    //     for (vector<ui>::reference j:i) cout<<setw(3)<<j;
    //     cout<<'\n';
    // }
    // cout<<"--------------\n";
    usi x, y, r;
    bool z;
    cin >> x >> y >> r >> z;
    --x, --y;
    for (usi i = 1; i <= r; i++) {
      usi sz = i << 1;
      for (usi j = 0; j < sz; j++) {
        usi px = x - i + j, py = y - i;
        ui tmp = a[px][py];
        for (unsigned char k = 0; k < 3; k++) {
          si nx = px - x, ny = py - y;
          swap(nx, ny), (z ? ny : nx) *= -1;
          nx += x, ny += y;
          // cout<<nx<<','<<ny<<' ';
          a[px][py] = a[nx][ny];
          px = nx, py = ny;
        }
        a[px][py] = tmp;
      }
    }
  }
  for (vector<vector<ui>>::reference i : a) {
    for (vector<ui>::reference j : i) cout << j << ' ';
    cout << '\n';
  }
  return 0;
}