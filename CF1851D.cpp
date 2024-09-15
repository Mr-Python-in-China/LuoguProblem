#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    li lst = 0, strange = 0;
    vector<bool> vis(n + 1);
    bool flag = true;
    for (size_t i = 1; i < n; i++) {
      li now;
      cin >> now;
      if (flag) {
        if (now - lst <= 0)
          flag = false;
        else if (now - lst > n) {
          if (strange)
            flag = false;
          else
            strange = now - lst;
        } else if (!vis[now - lst])
          vis[now - lst] = true;
        else if (strange)
          flag = false;
        else
          strange = now - lst;
      }
      lst = now;
    }
    if (lst != (n * n + n) >> 1) {
      li now = (n * n + n) >> 1;
      if (flag) {
        if (now - lst <= 0)
          flag = false;
        else if (now - lst > n) {
          if (strange)
            flag = false;
          else
            strange = now - lst;
        } else if (!vis[now - lst])
          vis[now - lst] = true;
        else if (strange)
          flag = false;
        else
          strange = now - lst;
      }
      lst = now;
    }
    if (flag) {
      size_t cnt = 0;
      for (size_t i = n; i > 0; i--)
        if (!vis[i]) strange -= i, cnt++;
      if (cnt > 2) flag = false;
      if (strange) flag = false;
    }
    cout << (flag ? "YES" : "NO") << '\n';
  }
  return 0;
}