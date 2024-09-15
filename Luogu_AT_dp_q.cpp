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
      if (no_matter(l, r)) return numeric_limits<uli>::min();
      if (in_interval(l, r)) return minv;
      return max(nodel->getMin(l, r), noder->getMin(l, r));
    }
    void set(size_t p, uli v) {
      if (invl == p && invr - invl == 1) return void(minv = v);
      if (no_matter(p, p + 1)) return;
      nodel->set(p, v), noder->set(p, v);
      minv = max(nodel->minv, noder->minv);
    }
  } root;

 public:
  SGtree(size_t n): root(0, n) {}
  uli getMin(size_t l, size_t r) { return root.getMin(l, r); }
  void set(size_t p, uli v) { return root.set(p, v); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<pair<ui, ui>> a(n);
  for (auto &i : a) cin >> i.first;
  for (auto &i : a) cin >> i.second;
  SGtree t(n + 1);
  for (auto const &i : a) {
    uli v = t.getMin(0, i.first) + i.second;
    if (v > t.getMin(i.first, i.first + 1)) t.set(i.first, v);
  }
  cout << t.getMin(0, n + 1);
  return 0;
}