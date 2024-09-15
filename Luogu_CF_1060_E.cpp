#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using Graph = vector<vector<size_t>>;
struct node {
  vector<node *> son;
  size_t sz;
  size_t id;
  node *fa;
  node(Graph mp, size_t p, node *_fa = nullptr): son(), sz(1), id(p), fa(_fa) {
    for (size_t i : mp[p])
      if (fa == nullptr || fa->id != i)
        son.emplace_back(new node(mp, i, this)), sz += son.back()->sz;
  }
};
uli dissum(node *p) {
  uli res = 0;
  for (node *i : p->son) res += dissum(i) + i->sz;
  return res;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  Graph mp(n);
  for (size_t i = 1; i < n; ++i) {
    size_t x, y;
    cin >> x >> y;
    --x, --y;
    mp[x].push_back(y), mp[y].push_back(x);
  }
  node *root = new node(mp, 0);
  cout << ;
  return 0;
}