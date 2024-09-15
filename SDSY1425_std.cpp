#include <stdio.h>

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
// #define int long long
// #define ldb long double
#define loop(i, x, y) for (ll i = x; i <= y; i++)
#define doop(i, x, y) for (ll i = x; i >= y; i--)
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Min(x, y) ((x) < (y) ? (x) : (y))
using namespace std;
typedef long long ll;
int read() {
  int x = 0, y = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') y = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x * y;
}
void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) { print(x / 10); }
  putchar(x % 10 + '0');
  return;
}
const int Mod = 998244353;
const long long INF = 0x7f7f7f7f;
const long long N = 1e7 + 5;
const long long M = 1e5 + 5;
int n, a[N];
int nxt[N], lst[N];
ll sum[N];
int last[N];
int ans = 1;
inline ll cal(ll x) { return x * (1 + x) / 2; }
vector<int> onepos;
void work(int x) {
  int l = x;
  int lim;
  while ((a[l] != 1 || l == x) && l > 0) {
    lim = nxt[l];
    //		printf("NowL %d lim %d\n",l,lim);
    loop(i, l + 1, lim && i <= n) {
      //			printf(" for %d nxt %d\n",i,nxt[i]);
      lim = Min(lim, nxt[i]);
      if (sum[i] - sum[l - 1] == cal(i - l + 1)) { ans = Max(ans, i - l + 1); }
    }
    if (sum[lim] - sum[l - 1] == cal(lim - l + 1)) {
      ans = Max(ans, lim - l + 1);
      //			printf("%d %d \n",lim,l);
    }
    l--;
  }
}
inline void workB(int x) {
  int l = x;
  int lim = 0;
  int i = l;
  while ((a[l] != 1 || l == x) && l > 0) {
    lim = Max(lim, nxt[l]);
    lim = Min(lim, n);
    //		printf("NowL %d lim %d\n",l,lim);
    for (; i <= lim && i <= n; i++) {
      //			printf(" for %d nxt %d\n",i,nxt[i]);
      lim = Min(lim, nxt[i]);
      if (sum[i] - sum[l - 1] == cal(i - l + 1)) { ans = Max(ans, i - l + 1); }
    }

    if (sum[lim] - sum[l - 1] == cal(lim - l + 1) && l > 0 && lim <= n) {
      ans = Max(ans, lim - l + 1);
      //			printf("%d %d \n",lim,l);
    }
    l--;
  }
}
inline void workA(int x) {
  int r = x;
  int lim = INF;
  int i = r;
  while ((a[r] != 1 || r == x) && r <= n) {
    lim = Min(lim, lst[r]);
    lim = Max(1, lim);
    for (; i >= lim && i > 0; i--) {
      lim = Max(lim, lst[i]);
      if (sum[r] - sum[i - 1] == cal(r - i + 1)) { ans = Max(ans, r - i + 1); }
    }
    if (sum[r] - sum[lim - 1] == cal(r - lim + 1) && lim > 0 && r <= n) {
      ans = Max(ans, r - lim + 1);
    }
    r++;
  }
}
signed main() {
  n = read();
  loop(i, 1, n) {
    a[i] = read(), sum[i] = sum[i - 1] + a[i];
    //		cout<<a[i]<<" ";
    if (a[i] == 1) onepos.push_back(i);
    nxt[i] = n;
    lst[i] = 1;
  }

  loop(i, 1, n) {
    if (last[a[i]]) { nxt[last[a[i]]] = i - 1; }
    last[a[i]] = i;
  }
  memset(last, 0, sizeof last);
  doop(i, n, 1) {
    if (last[a[i]]) lst[last[a[i]]] = i + 1;
    last[a[i]] = i;
  }

  loop(i, 0, (int)onepos.size() - 1) {
    if (n < 10000000) {
      work(onepos[i]);
    } else {
      workA(onepos[i]);
      workB(onepos[i]);
    }
  }
  printf("%d\n", ans);
  return 0;
}