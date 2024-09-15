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
  uli s = -m;
  graph mp(n);
  while (m--) {
    size_t x, y;
    cin >> x >> y;
    --x, --y;
    mp[x].emplace_back(y), mp[y].emplace_back(x);
  }
  vector<bool> vis(n);
  for (size_t i = 0; i < n; ++i)
    if (!vis[i]) {
      queue<size_t> q({i});
      vis[i] = true;
      size_t cnt = 0;
      while (!q.empty()) {
        size_t p = q.front();
        q.pop();
        ++cnt;
        for (size_t j : mp[p])
          if (!vis[j]) vis[j] = true, q.push(j);
      }
      s += cnt * (cnt - 1) / 2;
    }
  cout << s;
  return 0;
}