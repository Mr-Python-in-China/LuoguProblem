#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct TarjanNode {
  vector<TarjanNode*> nxt;
  size_t dfn, low, sz;
  bool isKeyPoint;
  TarjanNode(void): dfn(~0), low(~0) {}
  void tarjan(size_t tm = 0, TarjanNode* fa = nullptr) {
    dfn = low = tm++, sz = 1;
    size_t cnt = 0;
    for (TarjanNode* son : nxt)
      if (!~son->dfn) {
        son->tarjan(tm, this);
        tm += son->sz, sz += son->sz;
        low = min(low, son->low);
        if (son->low >= dfn) ++cnt;
      } else if (son != fa)
        low = min(low, son->dfn);
    isKeyPoint = cnt > !fa;
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  fin >> n >> m;
  vector<TarjanNode> mp(n);
  while (m--) {
    size_t x, y;
    fin >> x >> y;
    --x, --y;
    mp[x].nxt.emplace_back(&mp[y]), mp[y].nxt.emplace_back(&mp[x]);
  }
  for (TarjanNode& i : mp)
    if (!~i.dfn) i.tarjan();
  vector<size_t> ans;
  for (size_t i = 0; i < n; ++i)
    if (mp[i].isKeyPoint) ans.emplace_back(i);
  fout << ans.size() << '\n';
  for (size_t i : ans) fout << i + 1 << ' ';
  return 0;
}