#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    map<ui, set<ui>> s;
    vector<ui> cnt(n);
    for (size_t i = 0; i < n; ++i) {
      ui x;
      cin >> x;
      ++cnt[x];
    }
    for (ui i = 0; i < n; ++i)
      if (cnt[i]) s[cnt[i]].insert(i);
    set<ui> ans;
    bool flag = true;
    while (!s[1].empty()) {
      if (flag) ans.insert(*s[1].begin());
      --cnt[*s[1].begin()];
      s[1].erase(s[1].begin());
      flag = !flag;
    }
    for (ui i = 0; i < n; ++i)
      if (cnt[i]) ans.insert(i);
    size_t c = 0;
    for (; ans.count(c); ++c);
    cout << c << '\n';
  }
  return 0;
}