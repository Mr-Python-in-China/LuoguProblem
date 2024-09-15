#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<vector<size_t>>;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  graph mp(n);
  for (size_t i = 0; i < m; ++i) {
    size_t x, y;
    cin >> x >> y;
    --x, --y;
    mp[x].push_back(y), mp[y].push_back(x);
  }
  vector<vector<size_t>> dist(n, vector<size_t>(n, -1));
  for (size_t i = 0; i < n; ++i) {
    queue<size_t> q({i});
    dist[i][i] = 0;
    while (!q.empty()) {
      size_t p = q.front();
      q.pop();
      for (size_t j : mp[p])
        if (!~dist[i][j]) dist[i][j] = dist[i][p] + 1, q.push(j);
    }
  }
  size_t s1, t1, s2, t2, ans = -1;
  cin >> s1 >> t1 >> s2 >> t2;
  --s1, --s2;
  for (size_t i = 0; i < n; ++i)
    if (dist[0][i] + dist[i][s1] <= t1 && dist[0][i] + dist[i][s2] <= t2)
      ans = min(ans, dist[0][i] + dist[i][s1] + dist[i][s2]);
  ans == -1 ? cout << "-1" : cout << m - ans;
  return 0;
}