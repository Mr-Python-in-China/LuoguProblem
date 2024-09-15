#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct Edge {
  size_t u, v;
  uli w;
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  fin >> n >> m;
  vector<vector<uli>> dis(n, vector<uli>(n, numeric_limits<uli>::max() / 2));
  for (size_t i = 0; i < n; ++i) dis[i][i] = 0;
  vector<Edge> e(m);
  for (Edge& i : e) {
    fin >> i.u >> i.v >> i.w, --i.u, --i.v;
    dis[i.u][i.v] = min(dis[i.u][i.v], i.w),
    dis[i.v][i.u] = min(dis[i.v][i.u], i.w);
  }
  for (size_t k = 0; k < n; ++k)
    for (size_t i = 0; i < n; ++i)
      for (size_t j = 0; j < n; ++j)
        dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
  size_t q;
  fin >> q;
  while (q--) {
    size_t c;
    fin >> c;
    unordered_map<size_t, size_t> mapper;
    vector<size_t> b(c);
    for (size_t& i : b) {
      fin >> i, --i;
      mapper.emplace(e[i].u, ~0), mapper.emplace(e[i].v, ~0);
    }
    vector<size_t> revmapper;
    for (auto& i : mapper)
      i.second = revmapper.size(), revmapper.emplace_back(i.first);
    vector<vector<uli>> f(
        1u << c, vector<uli>(revmapper.size(), numeric_limits<uli>::max() / 2));
    for (size_t i = 0; i < revmapper.size(); ++i)
      f[0][i] = dis[0][revmapper[i]];
    for (size_t bit = 1; bit < f.size(); ++bit)
      for (size_t i = 0; i < c; ++i)
        if (bit & (1u << i)) {
          size_t fbit = bit ^ (1u << i);
          Edge const& ne = e[b[i]];
          for (size_t j = 0; j < revmapper.size(); ++j) {
            f[bit][mapper[ne.u]] =
                min(f[bit][mapper[ne.u]],
                    f[fbit][j] + dis[revmapper[j]][ne.v] + ne.w);
            f[bit][mapper[ne.v]] =
                min(f[bit][mapper[ne.v]],
                    f[fbit][j] + dis[revmapper[j]][ne.u] + ne.w);
          }
        }
    uli ans = numeric_limits<uli>::max();
    for (size_t i = 0; i < revmapper.size(); ++i)
      ans = min(ans, f.back()[i] + dis[revmapper[i]][n - 1]);
    fout << ans << '\n';
  }
  return 0;
}