#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
bool flag = true;
ui a, b, c;
array<char, 9> tst;
void dfs(ui deepth) {
  static bitset<9> vis;
  if (deepth >= 9) {
    ui x = tst[0] * 100 + tst[1] * 10 + tst[2],
       y = tst[3] * 100 + tst[4] * 10 + tst[5],
       z = tst[6] * 100 + tst[7] * 10 + tst[8];
    // if (a==192&&b==384&&c==576)
    //     cout<<(x%a==0)<<' '<<(y%b==0)<<' '<<(z%c==0)<<' '<<(x/a==y/b)<<'
    //     '<<(y/b==z/c)<<'\n';
    if (x % a == 0 && y % b == 0 && z % c == 0 && x / a == y / b &&
        y / b == z / c)
      flag = false, cout << x << ' ' << y << ' ' << z << '\n';
    return;
  }
  for (char i = 0; i < 9; i++)
    if (!vis[i]) {
      // cout<<deepth<<':'<<i<<'\n';
      vis[i] = true;
      tst[deepth] = i + 1;
      dfs(deepth + 1);
      vis[i] = false;
    }
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cin >> a >> b >> c;
  if (!a || !b || !c) {
    cout << "No!!!";
    return 0;
  }
  dfs(0);
  if (flag) cout << "No!!!";
  return 0;
}