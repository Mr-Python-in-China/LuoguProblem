// By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x, y, z) for (int x = (y); x <= (z); x++)
#define per(x, y, z) for (int x = (y); x >= (z); x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s)                   \
  do {                              \
    freopen(s ".in", "r", stdin);   \
    freopen(s ".out", "w", stdout); \
  } while (false)
using namespace std;
typedef long long ll;

mt19937 rnd(std::chrono::duration_cast<std::chrono::nanoseconds>(
                std::chrono::system_clock::now().time_since_epoch())
                .count());
int randint(int L, int R) {
  uniform_int_distribution<int> dist(L, R);
  return dist(rnd);
}

template <typename T> void chkmin(T& x, T y) {
  if (x > y) x = y;
}
template <typename T> void chkmax(T& x, T y) {
  if (x < y) x = y;
}

const int N = 2e3 + 5;

int T, n, t[N], b[N], a[N], s[N];

int main() {
  for (scanf("%d", &T); T; T--) {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &t[i]);
    rep(i, 1, n) scanf("%d", &b[i]);
    rep(i, 1, n) a[i] = 0;
    rep(i, 1, n) s[i] = t[i] + t[n - i + 1];
    bool ans = false;
    while (true) {
      bool valid = true;
      rep(i, 1, n) if (a[i] > b[i]) valid = false;
      if (!valid) break;
      if ((b[1] - a[1]) % s[1] == 0) {
        int steps = (b[1] - a[1]) / s[1];
        bool ok = true;
        rep(i, 1, n) if (b[i] != a[i] + steps * s[i]) ok = false;
        if (ok == true) {
          ans = true;
          break;
        }
      }
      rep(i, 1, n) a[i] += t[i];
    }
    puts(ans ? "Yes" : "No");
  }
  return 0;
}
