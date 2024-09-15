#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct TarjanNode {
  vector<TarjanNode *> nxt;
  vector<TarjanNode *> keySon;
  size_t dfn, low, sz;
  size_t id;
  bool keyPoint;
  TarjanNode(void): dfn(~0), keyPoint(false) {}
  void tarjan(size_t tm = 0, TarjanNode *fa = nullptr) {
    dfn = low = tm++;
    sz = 1;
    for (TarjanNode *son : nxt)
      if (!~son->dfn) {
        son->tarjan(tm, this);
        tm += son->sz;
        sz += son->sz;
        low = min(low, son->low);
        if (dfn <= son->low) keySon.emplace_back(son);
      } else if (son != fa)
        low = min(low, son->dfn);
    if (keySon.size() >= (fa == nullptr ? 2 : 1)) keyPoint = true;
  }
};
using Graph = vector<TarjanNode>;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  fin >> n >> m;
  Graph mp(n);
  while (m--) {
    size_t x, y;
    fin >> x >> y;
    --x, --y;
    mp[x].nxt.emplace_back(&mp[y]), mp[y].nxt.emplace_back(&mp[x]);
  }
  mp[0].tarjan();
  for (TarjanNode const &p : mp)
    if (p.keyPoint) {
      size_t ans = 0, sum = 1;
      for (TarjanNode *i : p.keySon) ans += i->sz * uli(n - i->sz), sum += i->sz;
      ans += uli(n - sum) * sum + (n - 1);
      fout << ans << '\n';
    } else
      fout << (n - 1) * 2 << '\n';
  return 0;
}