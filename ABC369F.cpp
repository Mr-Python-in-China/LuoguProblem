#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T, typename Cmp> class SGtree {
  class node {
    T maxx;
    size_t itvl, itvr;
    node *nodel, *noder;
    Cmp const& compare;
    bool in_inrerval(size_t l, size_t r) { return l <= itvl && itvr <= r; }
    bool no_matter(size_t l, size_t r) { return r <= itvl || itvr <= l; }

   public:
    node(size_t l, size_t r, Cmp const& _cmp, allocator<node> a)
        : maxx(),
          itvl(l),
          itvr(r),
          nodel(nullptr),
          noder(nullptr),
          compare(_cmp) {
      if (itvr - itvl > 1) {
        nodel = new node(l, l + ((r - l) >> 1), compare, a),
        noder = new node(l + ((r - l) >> 1), r, compare, a);
      } else
        maxx = T();
    }
    void set(size_t p, T val) {
      if (no_matter(p, p + 1)) return;
      if (in_inrerval(p, p + 1))
        maxx = val;
      else
        nodel->set(p, val), noder->set(p, val),
            maxx = max(nodel->maxx, noder->maxx, compare);
    }
    T query_max(size_t l, size_t r) {
      if (in_inrerval(l, r)) return maxx;
      if (no_matter(l, r)) return numeric_limits<T>::min();
      return max(nodel->query_max(l, r), noder->query_max(l, r), compare);
    }
  } root;

 public:
  SGtree(size_t n, Cmp const& cmp = less<>(),
         allocator<node> a = allocator<node>())
      : root(0, n, cmp, a) {}
  void add_interval(size_t l, size_t r, T const& v) {
    root.add_interval(l, r, v);
  }
  void set(size_t p, T val) { root.set(p, val); }
  T query_max(size_t l, size_t r) { return root.query_max(l, r); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, k;
  fin >> n >> m >> k;
  vector<vector<size_t>> p(n);
  for (size_t i = 0; i < k; ++i) {
    ui x, y;
    fin >> x >> y;
    p[--x].emplace_back(--y);
  }
  vector<unordered_map<size_t, ui>> f(n);
  f[0][0] = 0;
  vector<unordered_map<size_t, pair<size_t, size_t>>> pre(n);
  auto getF = [&f](pair<size_t, size_t> const& p) {
    try {
      return f[p.first].at(p.second);
    } catch (out_of_range const&) { return 0u; }
  };
  auto cmp = [&f, &getF](pair<size_t, size_t> const& x,
                         pair<size_t, size_t> const& y) {
    return getF(x) < getF(y);
  };
  SGtree<pair<size_t, size_t>, decltype(cmp)> tree(m, cmp);
  pair<size_t, size_t> end = {0, 0};
  for (size_t x = 0; x < n; ++x) {
    sort(p[x].begin(), p[x].end());
    for (size_t y : p[x]) {
      pair<size_t, size_t> maxp = tree.query_max(0, y + 1);
      if ((f[x][y] = getF(maxp) + 1) > getF(end)) end = {x, y};
      if (f[x][y] > getF(tree.query_max(y, y + 1))) tree.set(y, {x, y});
      pre[x][y] = maxp;
    }
  }
  fout << getF(end) << '\n';
  vector<pair<size_t, size_t>> stk = {pair<size_t, size_t>(n - 1, m - 1)};
  for (auto i = end; i != pair<size_t, size_t>{0, 0};
       i = pre[i.first][i.second])
    stk.emplace_back(i);
  stk.emplace_back(0, 0);
  for (auto it = stk.rbegin(), jt = next(it); jt != stk.rend(); ++it, ++jt) {
    for (size_t i = it->first; i < jt->first; ++i) fout.put('D');
    for (size_t i = it->second; i < jt->second; ++i) fout.put('R');
  }
  return 0;
}