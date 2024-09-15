#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<vector<pair<size_t, ui>>> mp(n);
  vector<size_t> d(n);
  while (m--) {
    size_t u, v;
    ui w;
    cin >> u >> v >> w;
    --u, --v;
    mp[u].emplace_back(v, w);
    ++d[v];
  }
  queue<size_t> q({0});
  vector<float> f(n), g(n);
  g[0] = 1;
  while (!q.empty()) {
    size_t p = q.front();
    q.pop();
    for (auto const &i : mp[p]) {
      g[i.first] += g[p] / mp[p].size();
      f[i.first] += (f[p] + i.second * g[p]) * 1.0 / mp[p].size();
      if (--d[i.first] == 0) q.push(i.first);
    }
  }
  cout << fixed << setprecision(2) << f[n - 1];
  return 0;
}