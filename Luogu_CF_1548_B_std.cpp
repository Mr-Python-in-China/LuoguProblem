#include <bits/stdc++.h>
#define INF 1e9
#define eps 1e-6
typedef long long ll;
using namespace std;

int t, n, ans;
ll a[200010], sub[200010], st[200010][20];

ll gcd(ll x, ll y) {
  if (!y) return x;
  return gcd(y, x % y);
}

ll query(int i, int j) {
  int k = log2(j - i + 1);
  return gcd(st[i][k], st[j - (1 << k) + 1][k]);
}

inline int max(int a, int b) { return a > b ? a : b; }

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    if (n == 1) {
      puts("1");
      continue;
    }
    for (int i = 1; i < n; i++) {
      sub[i] = a[i] - a[i + 1];
      if (sub[i] < 0) sub[i] = -sub[i];
    }
    n--;
    for (int i = 1; i <= n; i++) st[i][0] = sub[i];
    for (int j = 1; (1 << j) <= n; j++)
      for (int i = 1; i + (1 << j) - 1 <= n; i++)
        st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    ans = 0;
    for (int i = 1, l, r; i <= n; i++) {
      l = i, r = n;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (query(i, mid) == 1)
          r = mid - 1;
        else
          l = mid;
      }
      if (sub[i] != 1) ans = max(ans, l - i + 1);  // sub[i] = 1 时不可取答案
    }
    printf("%d\n", ans + 1);
  }

  return 0;
}
