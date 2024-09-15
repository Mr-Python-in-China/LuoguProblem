#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<vector<size_t>>;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t h, w;
  cin >> h >> w;
  vector<vector<bool>> mp(h, vector<bool>(w));
  pair<size_t, size_t> s, t;
  for (size_t i = 0; i < h; ++i)
    for (size_t j = 0; j < w; ++j) {
      char c;
      cin >> c;
      mp[i][j] = c == '#';
      if (c == 'S') s = {i, j};
      if (c == 'T') t = {i, j};
    }
  size_t n;
  cin >> n;
  vector<pair<pair<size_t, size_t>, ui>> e(n);
  vector<vector<size_t>> g(h, vector<size_t>(w, ~0));
  for (size_t i = 0; i < n; ++i)
    cin >> e[i].first.first >> e[i].first.second >> e[i].second,
        g[--e[i].first.first][--e[i].first.second] = i;
  if (!~g[s.first][s.second]) {
    cout << "No";
    return 0;
  }
  e.emplace_back(t, 0);
  g[t.first][t.second] = n++;
  graph nmp(n);
  for (size_t i = 0; i < n; ++i) {
    queue<pair<size_t, size_t>> q({e[i].first});
    vector<vector<ui>> r(h, vector<ui>(w, 0));
    r[e[i].first.first][e[i].first.second] = e[i].second;
    while (!q.empty()) {
      pair<size_t, size_t> p = q.front();
      q.pop();
      if (~g[p.first][p.second]) nmp[i].emplace_back(g[p.first][p.second]);
      if (r[p.first][p.second] == 0) continue;
      for (pair<size_t, size_t> d : {
               pair<size_t, size_t>{-1,  0},
                pair<size_t, size_t>{ 0, -1},
               pair<size_t, size_t>{ 1,  0},
                pair<size_t, size_t>{ 0,  1}
      }) {
        pair<size_t, size_t> np{p.first + d.first, p.second + d.second};
        if (np.first < h && np.second < w && !mp[np.first][np.second] &&
            r[np.first][np.second] == 0)
          q.push(np), r[np.first][np.second] = r[p.first][p.second] - 1;
      }
    }
  }
  {
    queue<size_t> q({g[s.first][s.second]});
    vector<bool> vis(n);
    vis[g[s.first][s.second]] = true;
    while (!q.empty()) {
      size_t p = q.front();
      q.pop();
      for (size_t i : nmp[p])
        if (!vis[i]) vis[i] = true, q.push(i);
    }
    if (vis.back())
      cout << "Yes";
    else
      cout << "No";
  }
  return 0;
}