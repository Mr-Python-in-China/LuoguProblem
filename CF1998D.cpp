#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
class SGtree {
  struct node {
    size_t invl, invr;
    uli minv;
    node *nodel, *noder;
    node(size_t l, size_t r): invl(l), invr(r), minv() {
      if (r - l == 1)
        nodel = noder = nullptr;
      else {
        size_t mid = (r - l) / 2 + l;
        nodel = new node(l, mid), noder = new node(mid, r);
      }
    }
    bool in_interval(size_t l, size_t r) { return l <= invl && invr <= r; }
    bool no_matter(size_t l, size_t r) { return invr <= l || r <= invl; }
    uli getMin(size_t l, size_t r) {
      if (no_matter(l, r)) return numeric_limits<uli>::max();
      if (in_interval(l, r)) return minv;
      return min(nodel->getMin(l, r), noder->getMin(l, r));
    }
    void set(size_t p, uli v) {
      if (invl == p && invr - invl == 1) return void(minv = v);
      if (no_matter(p, p + 1)) return;
      nodel->set(p, v), noder->set(p, v);
      minv = min(nodel->minv, noder->minv);
    }
  } root;

 public:
  SGtree(size_t n): root(0, n) {}
  uli getMin(size_t l, size_t r) { return root.getMin(l, r); }
  void set(size_t p, uli v) { return root.set(p, v); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  fin >> T;
  while (T--) {
    size_t n, m;
    cin >> n >> m;
    vector<vector<size_t>> mp(n);
    while (m--) {
      size_t x, y;
      cin >> x >> y;
      if (y - x == 1) continue;
      mp[--x].emplace_back(--y);
    }
    SGtree f(n);
    for (size_t i = 0; i < n; ++i) f.set(i, numeric_limits<uli>::max() / 2);
    f.set(0, n);
    for (size_t p = 0; p < n - 1; ++p) {
      cout << (f.getMin(p, n) < n - p ? '0' : '1');
      ui x = f.getMin(p, p + 1) - (n - p);
      for (size_t i : mp[p])
        if (f.getMin(i, i + 1) - (n - i) > x + 1) f.set(i, x + 1 + (n - i));
      if (f.getMin(p + 1, p + 2) - (n - (p + 1)) > x + 1)
        f.set(p + 1, x + 1 + (n - (p + 1)));
    }
    cout << '\n';
  }
  return 0;
}