#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct SGtree {
  struct node {
    node *nodel, *noder;
    size_t invl, invr;
    int sumv, maxv;
    template <typename RandomContainer>
    node(RandomContainer a, size_t l, size_t r)
        : nodel(nullptr), noder(nullptr), invl(l), invr(r) {
      if (r - l > 1) {
        size_t mid = (l + r) / 2;
        nodel = new node(a, l, mid), noder = new node(a, mid, r);
        sumv = sum(nodel->sumv + noder->sumv),
        maxv = max(nodel->maxv, noder->maxv);
      } else
        sumv = maxv = a[l];
    }
    bool in_interval(size_t l, size_t r) { return l <= invl && r <= invr; }

    int getsum(size_t l, size_t r) {}
  } root;
};

void init_son(vector<vector<size_t>> const& mp, vector<size_t>& d,
              vector<size_t>& sz, vector<vector<size_t>>& sons, size_t p,
              size_t fa = ~0) {
  d[p] = ~fa ? d[fa] : 0;
  for (size_t i : mp[p])
    if (i != fa) {
      init_son(mp, d, sz, sons, i, p);
      sz[p] += sz[i];
      sons[p].push_back(i);
    }
  sort(sons[p].begin(), sons[p].end(),
       [&sz](size_t x, size_t y) { return sz[x] > sz[y]; });
}
void init_top(vector<vector<size_t>> const& tree, vector<size_t> const& sz,
              vector<size_t>& top, vector<size_t>& dfn, size_t p,
              size_t t = 0) {
  dfn[p] = t++;
  for (size_t i : tree[p]) {
    init_top(tree, sz, top, dfn, i, t);
    t += sz[i];
  }
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<vector<size_t>> mp(n);
  for (size_t i = 1; i < n; ++i) {
    size_t x, y;
    cin >> x >> y;
    --x, --y;
    mp[x].push_back(y), mp[y].push_back(x);
  }
  vector<size_t> d(n), sz(n);
  vector<vector<size_t>> sons(n);
  init_son(mp, d, sz, sons, 0);
  vector<size_t> top(n), dfn(n);
  init_top(mp, sz, top, dfn, 0);
  vector<short int> v(n);
  for (short int& i : v) cin >> i;
  size_t q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    if (s == "QMAX") {
    } else if (s == "QSUM") {
    } else if (s == "CHANGE") {
    }
  }
  return 0;
}