#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  map<size_t, pair<size_t, ui>> s;
  for (size_t i = 0; i < n; ++i) s[i].first = i + 1, cin >> s[i].second;
  size_t m;
  cin >> m;
  while (m--) {
    size_t l, r;
    ui x;
    cin >> l >> r >> x;
    --l;
    map<size_t, pair<size_t, ui>>::const_iterator it = prev(s.upper_bound(l)),
                                                  jt = s.lower_bound(r);
    pair<size_t, pair<size_t, ui>> lv = *it, rv = *prev(jt);
    ui d = 0;
    for (auto p = it; p != jt; p = s.erase(p)) d = max(d, p->second.second);
    if (lv.first < l)
      s.insert({
          lv.first, {l, lv.second.second}
      });
    if (r < rv.second.first)
      s.insert({
          r, {rv.second.first, rv.second.second}
      });
    s.insert({
        l, {r, d + x}
    });
    cout << d << '\n';
  }

  return 0;
}