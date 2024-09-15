#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, h, w, a[15], b[15], num[15];
bool vis[15], c[15][15];

void dfs(int x) {
  if (x == n + 1) {
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) c[i][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
      bool FLAG = false;
      for (int j = 1; j <= h; j++) {
        for (int k = 1; k <= w; k++) {
          if (a[num[i]] + j - 1 > h || b[num[i]] + k - 1 > w) continue;
          bool flag = false;
          for (int l = j; l <= j + a[num[i]] - 1; l++) {
            for (int r = k; r <= k + b[num[i]] - 1; r++) {
              if (c[l][r]) flag = true;
            }
          }
          if (!flag) {
            for (int l = j; l <= j + a[num[i]] - 1; l++) {
              for (int r = k; r <= k + b[num[i]] - 1; r++) { c[l][r] = 1; }
            }
            FLAG = true;
            break;
          }
        }
        if (FLAG) break;
      }
    }
    bool flag = false;
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        if (!c[i][j]) flag = true;
      }
    }
    if (!flag) {
      cout << "Yes" << endl;
      exit(0);
    }
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      vis[i] = 1;
      num[x] = i;
      dfs(x + 1);
      vis[i] = 0;
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> h >> w;
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 1; j <= n; j++) {
      if ((i & (1 << (j - 1)))) { swap(a[j], b[j]); }
    }
    for (int j = 1; j <= n; j++) vis[j] = 0;
    dfs(1);
    for (int j = 1; j <= n; j++) {
      if ((i & (1 << (j - 1)))) { swap(a[j], b[j]); }
    }
  }
  cout << "No" << endl;
  return 0;
}