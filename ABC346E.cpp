#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct ask {
  bool op;
  size_t a;
  ui c;
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t h, w;
  size_t m;
  cin >> h >> w >> m;
  uli t = (uli)h * w;
  vector<bool> vish(h), visw(w);
  vector<ask> q(m);
  map<ui, uli> ans;
  for (ask& i : q) {
    char b;
    cin >> b >> i.a >> i.c;
    --i.a, i.op = b == '1';
  }
  reverse(q.begin(), q.end());
  for (ask const& i : q) {
    if ((i.op ? vish : visw)[i.a]) continue;
    (i.op ? vish : visw)[i.a] = true;
    ans[i.c] += i.op ? w : h;
    --(i.op ? h : w);
  }
  ans.erase(0);
  for (auto i = ans.begin(); i != ans.end();) {
    t -= i->second;
    i->second ? ++i : i = ans.erase(i);
  }
  if (t) ans[0] = t;
  cout << ans.size() << '\n';
  for (pair<ui, uli> const& i : ans) cout << i.first << ' ' << i.second << '\n';
  return 0;
}