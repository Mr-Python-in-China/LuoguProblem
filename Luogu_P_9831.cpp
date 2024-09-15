#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct forder {
  unordered_map<string, forder*> sub;
  bool flag = false;
  size_t f(void) {
    if (sub.empty()) return flag;
    ui ans = 0;
    flag = true;
    for (auto& i : sub) {
      ans += i.second->f();
      if (!i.second->flag) flag = false;
    }
    if (flag) ans = 1;
    return ans;
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    forder root;
    size_t n, m;
    cin >> n >> m;
    while (n--) {
      forder* p = &root;
      string s;
      cin >> s;
      s += '/';
      string t;
      for (char i : s)
        if (i != '/')
          t += i;
        else {
          if (!p->sub[t]) p->sub[t] = new forder;
          p = p->sub[t];
          t.clear();
        }
      p->flag = true;
    }
    while (m--) {
      forder* p = &root;
      string s;
      cin >> s;
      s += '/';
      string t;
      for (char i : s)
        if (i != '/')
          t += i;
        else {
          if (!p->sub[t]) p->sub[t] = new forder;
          p = p->sub[t];
          t.clear();
        }
    }
    root.f();
    ui ans = 0;
    for (auto& i : root.sub) ans += i.second->f();
    cout << ans << '\n';
  }
  return 0;
}