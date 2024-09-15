#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct items_base {
  ui v, w;
  items_base(ui _v, ui _w): v(_v), w(_w * _v) {}
};
struct items: items_base {
  vector<items_base> sub;
  items(ui _v, ui _w): items_base(_v, _w), sub() {}
  vector<items_base> allobj(void) {
    vector<items_base> res;
    for (size_t i = 0; i < (1 << sub.size()); ++i) {
      res.emplace_back(*this);
      size_t x = i;
      for (size_t j = 0; x; ++j, x >>= 1)
        if (x & 1) res.back().v += sub[j].v, res.back().w += sub[j].w;
    }
    return res;
  }
};
struct inp {
  ui v, p;
  size_t q, id;
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n;
  size_t m;
  cin >> n >> m;
  n /= 10;
  unordered_map<size_t, size_t> mp;
  vector<items> a;
  vector<inp> tmp(m);
  for (size_t i = 0; i < m; ++i)
    cin >> tmp[i].v >> tmp[i].p >> tmp[i].q, tmp[i].id = i + 1;
  sort(tmp.begin(), tmp.end(),
       [](inp const& a, inp const& b) { return a.q < b.q; });
  for (size_t i = 0; i < m; ++i) {
    ui v = tmp[i].v /= 10, p = tmp[i].p;
    size_t q = tmp[i].q;
    if (q == 0)
      mp[tmp[i].id] = a.size(), a.emplace_back(v, p);
    else
      a[mp[q]].sub.emplace_back(v, p);
  }
  vector<ui> f(n + 1);
  for (items& i : a) {
    vector<items_base> ao(i.allobj());
    for (ui j = n; j > 0; --j)
      for (items_base& k : ao)
        if (k.v <= j) f[j] = max(f[j], f[j - k.v] + k.w);
  }
  cout << f[n] * 10;
  return 0;
}