#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
ui P;
void init_son(vector<vector<size_t>> const& mp, vector<vector<size_t>>& son,
              vector<size_t>& sz, size_t p, size_t fa = ~0) {
  for (size_t i : mp[p])
    if (i != fa) {
      init_son(mp, son, sz, i, p);
      sz[p] += sz[i];
      son[p].push_back(i);
    }
  sort(son[p].begin(), son[p].end(),
       [&sz](size_t x, size_t y) { return sz[x] > sz[y]; });
}
void init_dfn(vector<vector<size_t>> const& son, vector<size_t> const& sz,
              vector<size_t>& dfn, vector<size_t>& top, size_t p, size_t s,
              size_t t) {
  dfn[p] = t++, top[p] = s;
  if (son.empty()) return;
  init_dfn(son, sz, dfn, top, son[p].front(), s, t);
  t += sz[son[p].front()];
  for_each(next(son[p].begin()), son[p].end(), [&](size_t i) {
    init_dfn(son, sz, dfn, top, i, i, t);
    t += sz[i];
  });
}
struct SGtree {
  struct node {
    node *nodel, *noder;
    size_t invl, invr;
    li sum;
    li lazy;
    bool in_interval(size_t l, size_t r) { return l <= invl && invr <= r; }
    bool no_matter(size_t l, size_t r) { return r <= invl || invr <= l; }
    void update(void) {
      if (nodel && noder)
        nodel->sum += lazy * (nodel->invr - nodel->invl),
            noder->sum += lazy * (noder->invl - noder->invl);
      lazy = 0;
    }
    node(size_t l, size_t r): invl(l), invr(r), sum(), lazy() {
      if (r - l == 1)
        nodel = noder = nullptr;
      else {
        size_t m = (l + r) / 2;
        nodel = new node(l, m), noder = new node(m, r);
      }
    }
    void interval_add(size_t l, size_t r, li x) {
      if (in_interval(l, r))
        sum += x * (r - l);
      else if (no_matter(l, r))
        ;
      else
        nodel->interval_add(l, r, x), noder->interval_add(l, r, x);
    }
    li interval_sum(size_t l, size_t r) {
      if (in_interval(l, r))
        return sum;
      else if (no_matter(l, r))
        return 0;
      else {
        update();
        return nodel->interval_sum(l, r) + noder->interval_sum(l, r);
      }
    }
  };
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, r;
  cin >> n >> m >> r >> P;

  return 0;
}