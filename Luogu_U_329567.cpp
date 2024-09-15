#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using graph = vector<vector<size_t>>;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  if (m == 1) return cout << '1', 0;
  graph mp(n);
  vector<size_t> abled;
  for (size_t i = 0; i < n; ++i) {
    bool b;
    cin >> b;
    if (b) abled.push_back(i);
  }
  for (size_t i = 1; i < n; ++i) {
    size_t x, y;
    cin >> x >> y;
    --x, --y;
    mp[x].push_back(y), mp[y].push_back(x);
  }
  vector<vector<size_t>> dis(n, vector<size_t>(n, -1));
  for (size_t i = 0; i < n; ++i) {
    queue<size_t> q({i});
    dis[i][i] = 0;
    while (!q.empty()) {
      size_t p = q.front();
      q.pop();
      for (size_t const& j : mp[p])
        if (dis[i][j] == -1) dis[i][j] = dis[i][p] + 1, q.push(j);
    }
  }
  size_t ans = -1;
  for (size_t i = 1 << abled.size() - 1; ~i; --i) {
    vector<size_t> choose;
    size_t x = i;
    for (size_t c = 0; x; ++c, x >>= 1)
      if (x & 1) choose.push_back(c);
    if (choose.size() < m) continue;
    size_t maxdis = 0;
    for (vector<size_t>::iterator it = choose.begin(); it < choose.end(); it++)
      for (vector<size_t>::iterator jt = next(it); jt < choose.end(); jt++)
        maxdis = max(maxdis, dis[*it][*jt]);
    ans = min(maxdis, ans);
  }
  cout << ans;
  return 0;
}