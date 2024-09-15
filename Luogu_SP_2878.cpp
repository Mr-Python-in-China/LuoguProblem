#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct TarjanNode {
  unordered_set<TarjanNode*> nxt;
  size_t dfn, low, sz, id;
  TarjanNode(void): dfn(~0) {}
  void tarjan(vector<unordered_set<TarjanNode*>>& vDDC, stack<TarjanNode*>& stk,
              size_t tm = 0, TarjanNode* fa = nullptr) {
    dfn = low = tm++, sz = 1, stk.push(this);
    for (TarjanNode* son : nxt)
      if (!~son->dfn) {
        son->tarjan(vDDC, stk, tm, this);
        tm += son->sz, sz += son->sz;
        low = min(low, son->low);
        if (son->low >= dfn) {
          vDDC.emplace_back();
          while (stk.top() != son) vDDC.back().emplace(stk.top()), stk.pop();
          vDDC.back().emplace(stk.top()), stk.pop();
          vDDC.back().emplace(this);
        }
      } else if (son != fa)
        low = min(low, son->dfn);
  }
};
struct BinaryNode {
  vector<BinaryNode*> nxt;
  signed char color;
  BinaryNode(void): color(~0) {}
  bool checkBinaryNode(bool c = 0) {
    if (color != -1) return color == c;
    color = c;
    for (BinaryNode* son : nxt)
      if (!son->checkBinaryNode(!c)) return false;
    return true;
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  fin >> n >> m;
  if (n == 0) return 0;
  vector<TarjanNode> mp(n);
  for (size_t i = 0; i < n; ++i) mp[i].id = i;
  for (TarjanNode& i : mp)
    for (TarjanNode& j : mp)
      if (&i != &j) i.nxt.emplace(&j);
  while (m--) {
    size_t x, y;
    fin >> x >> y;
    --x, --y;
    mp[x].nxt.erase(&mp[y]), mp[y].nxt.erase(&mp[x]);
  }
  vector<unordered_set<TarjanNode*>> vDDC;
  for (TarjanNode& i : mp)
    if (!~i.dfn) {
      stack<TarjanNode*> stk;
      i.tarjan(vDDC, stk);
    }
  vector<size_t> ans(n, true);
  for (unordered_set<TarjanNode*> const& s : vDDC) {
    vector<BinaryNode> g(n);
    for (TarjanNode& i : mp)
      if (s.count(&i))
        for (TarjanNode* j : i.nxt)
          if (s.count(j)) g[i.id].nxt.emplace_back(&g[j->id]);
    if (!g[(*s.begin())->id].checkBinaryNode())
      for (TarjanNode* i : s) ans[i->id] &= false;
  }
  fout << accumulate(ans.begin(), ans.end(), size_t(0)) << '\n';
  return main();
}