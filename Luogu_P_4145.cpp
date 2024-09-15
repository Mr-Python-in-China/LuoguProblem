#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> struct SGtree {
  struct node {
    size_t invl, invr;
    T sum;
    bool allone;
    node *nodel, *noder;
    bool in_interval(size_t l, size_t r) { return l <= invl && invr <= r; }
    bool no_matter(size_t l, size_t r) { return r <= invl || invr <= l; }
    template <typename RandomIterator>
    node(RandomIterator it, size_t l, size_t r)
        : invl(l), invr(r), allone(false), nodel(), noder() {
      if (r - l > 1) {
        size_t mid = (l + r) / 2;
        nodel = new node(it, l, mid), noder = new node(it + (mid - l), mid, r);
        sum = nodel->sum + noder->sum;
        if (nodel->allone && noder->allone) allone = true;
      } else if ((sum = *it) == 1)
        allone = true;
    }
    void sqrt(size_t l, size_t r) {
      if (no_matter(l, r)) return;
      if (allone) return;
      if (invr - invl == 1)
        if ((sum = std::sqrt(sum)) == 1)
          allone = true;
        else
          ;
      else {
        nodel->sqrt(l, r), noder->sqrt(l, r);
        sum = nodel->sum + noder->sum;
        if (nodel->allone && noder->allone) allone = true;
      }
    }
    T getsum(size_t l, size_t r) {
      if (no_matter(l, r)) return T();
      if (in_interval(l, r)) return sum;
      return nodel->getsum(l, r) + noder->getsum(l, r);
    }
  } root;
  SGtree(vector<T> const& a): root(a.cbegin(), 0, a.size()) {}
  void sqrt(size_t l, size_t r) { return root.sqrt(l, r); }
  T sum(size_t l, size_t r) { return root.getsum(l, r); }
};

int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<uli> a(n);
  for (uli& i : a) cin >> i;
  SGtree<uli> t(a);
  size_t m;
  cin >> m;
  while (m--) {
    char op;
    size_t l, r;
    cin >> op >> l >> r;
    if (l > r) swap(l, r);
    --l;
    if (op == '0')
      t.sqrt(l, r);
    else if (op == '1')
      cout << t.sum(l, r) << '\n';
    else
      throw;
  }
  return 0;
}