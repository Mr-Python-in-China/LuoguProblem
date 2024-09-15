#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using Graph = vector<unordered_set<size_t>>;
template <typename C, typename V> void changeInStatus(C& c, V const& v) {
  auto p = c.insert(v);
  if (!p.second) c.erase(p.first);
}
constexpr ui P = 1e9 + 7;
ui& addMod(ui& x, ui y) {
  if ((x += y) >= P) x -= P;
  return x;
}
vector<ui> f(size_t p, ui v, Graph const& mp, size_t fa = ~0) {
  if (v == 0) return {0};
  vector<ui> g(v + 1);
  g[1] = 1;
  for (size_t i : mp[p])
    if (i != fa) {
      vector<ui> h(g);
      vector<ui> t = f(i, v - 1, mp, p);
      for (ui i = 0; i <= v; ++i)
        for (ui j = 0; j <= i && j < v; ++j)
          h[i] = (g[i] + (uli)g[i - j] * t[j]) % P;
      g = h;
    }
  return g;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, Q;
  fin >> n >> Q;
  Graph mp(n);
  for (size_t i = 1; i < n; ++i) {
    size_t x, y;
    fin >> x >> y;
    --x, --y;
    mp[x].emplace(y), mp[y].emplace(x);
  }
  while (Q--) {
    char op;
    fin >> op;
    if (op == '0') {
      size_t x, y;
      fin >> x >> y;
      --x, --y;
      changeInStatus(mp[x], y), changeInStatus(mp[y], x);
    } else if (op == '1') {
      size_t x;
      ui y;
      fin >> x >> y;
      fout << f(--x, y, mp)[y] << '\n';
    }
  }
  return 0;
}