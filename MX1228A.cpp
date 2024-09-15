#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T, typename = is_unsigned<T>>
constexpr T abs_minus(T const &a, T const &b) {
  return max(a, b) - min(a, b);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, x;
  fin >> n >> m >> x;
  vector<pair<ui, ui>> node(m + 2);
  for (pair<ui, ui> &i : node) fin >> i.first >> i.second;
  auto const huffmanDis = [&node](size_t a, size_t b) {
    return abs_minus(node[a].first, node[b].first) +
           abs_minus(node[a].second, node[b].second);
  };
  ui l = 1, r = 2e9 + 154220;
  while (l < r) {
    ui k = (l + r) / 2;
    vector<ui> dis(m + 2, numeric_limits<ui>::max() / 2);
    vector<bool> vis(m + 2);
    dis[0] = 0;
    for (size_t t = 0; t < m + 2; ++t) {
      size_t p = ~0;
      for (size_t i = 0; i < m + 2; ++i)
        if (!vis[i] && (p == (size_t)~0 || dis[p] > dis[i])) p = i;
      vis[p] = true;
      for (size_t i = 0; i < m + 2; ++i)
        dis[i] = min(dis[i], dis[p] + (huffmanDis(i, p) - 1) / k);
    }
    dis[1] <= x ? r = k : l = k + 1;
  }
  fout << l;
  return 0;
}