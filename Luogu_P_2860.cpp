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
  unordered_set<TarjanNode*> keyEdge;
  size_t dfn, low, sz, color;
  TarjanNode(void): dfn(~0), low(~0), color(~0) {}
  void tarjan(size_t tm = 0, TarjanNode* fa = nullptr) {
    dfn = low = tm++, sz = 1;
    for (TarjanNode* son : nxt)
      if (!~son->dfn) {
        son->tarjan(tm, this);
        tm += son->sz, sz += son->sz;
        low = min(low, son->low);
        if (son->low > dfn) keyEdge.emplace(son), son->keyEdge.emplace(this);
      } else if (son != fa)
        low = min(low, son->dfn);
  }
  void fillColorWithoutKeyEdge(size_t target) {
    color = target;
    for (TarjanNode* son : nxt)
      if (!~son->color && !keyEdge.count(son))
        son->fillColorWithoutKeyEdge(target);
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
  mp[0].tarjan();
  size_t gid = 0;
  for (TarjanNode& i : mp)
    if (!~i.color) i.fillColorWithoutKeyEdge(gid++);
  vector<size_t> deg(gid);
  for (TarjanNode& i : mp) deg[i.color] += i.keyEdge.size();
  fout << (count(deg.begin(), deg.end(), 1) + 1) / 2;
  return 0;
}