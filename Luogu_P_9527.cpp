#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr size_t MAXD = 41;
ui p;
struct Node {
  Node* fa;
  array<ui, MAXD> tag;
  Node(void): fa(nullptr) { tag.fill(1); }
  void set(size_t d, ui x) {
    if (d == 0) return void(tag[0] = (uli)tag[0] * x % p);
    fa->set(d - 1, x);
    tag[d - 1] = (uli)tag[d - 1] * x % p, tag[d] = (uli)tag[d] * x % p;
  }
  ui get(size_t d = 0) {
    if (d == MAXD) return 1;
    return uli(fa ? fa->get(d + 1) : 1u) * tag[d] % p;
  }
};
void initTree(vector<vector<size_t>> const& mp, vector<Node>& tree,
              size_t p = 0) {
  for (size_t i : mp[p])
    if (&tree[i] != tree[p].fa) {
      tree[i].fa = &tree[p];
      initTree(mp, tree, i);
    }
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  fin >> n >> p;
  vector<vector<size_t>> mp(n);
  for (size_t i = 1; i < n; ++i) {
    ui x, y;
    fin >> x >> y;
    --x, --y;
    mp[x].emplace_back(y), mp[y].emplace_back(x);
  }
  vector<ui> g(n);
  for (ui& i : g) fin >> i;
  vector<Node> tree(n);
  array<Node, MAXD> virt;
  for (size_t i = 1; i < MAXD; ++i) virt[i].fa = &virt[i - 1];
  tree[0].fa = &virt.back();
  initTree(mp, tree);
  size_t q;
  fin >> q;
  while (q--) {
    char c;
    fin >> c;
    if (c == '1') {
      size_t x, d;
      ui w;
      fin >> x >> d >> w;
      tree[--x].set(d, w);
    } else if (c == '2') {
      size_t x;
      fin >> x;
      --x;
      fout << tree[x].get() * (uli)g[x] % p << '\n';
    }
  }
  return 0;
}