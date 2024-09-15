#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<vector<size_t>>;
vector<size_t> bfs(graph const &mp, size_t s = 0) {
  vector<size_t> ans(mp.size(), ~0);
  ans[s] = 0;
  queue<size_t> q({s});
  while (!q.empty()) {
    size_t p = q.front();
    q.pop();
    for (size_t i : mp[p])
      if (!~ans[i]) ans[i] = ans[p] + 1, q.push(i);
  }
  return ans;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, s, t;
    cin >> n >> s >> t;
    --s, --t;
    graph mp(n);
    for (size_t i = 1; i < n; ++i) {
      size_t x, y;
      cin >> x >> y;
      --x, --y;
      mp[x].push_back(y), mp[y].push_back(x);
    }
    vector<size_t> ds = bfs(mp, s), dt = bfs(mp, t);
    size_t mid = ~0;
    for (size_t i = 0; i < n; ++i)
      if (ds[i] == dt[i] || dt[i] - ds[i] == 1) {
        if (ds[i] < ds[mid]) mid = i;
      }
    assert(~mid);
    vector<size_t> dmid = bfs(mp, mid);
    cout << (n - 1) * 2 - *max_element(dmid.begin(), dmid.end()) +
                max(ds[mid], dt[mid])
         << '\n';
  }
  return 0;
}