#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct Train {
  ui l, d, k, c;
  size_t a, b;
};
vector<uli> dij(vector<vector<Train>> const& mp) {
  pbds::priority_queue<pair<uli, size_t>, less<pair<uli, size_t>>,
                       pbds::thin_heap_tag>
      q;
  q.push({numeric_limits<uli>::max(), mp.size() - 1});
  vector<uli> dis(mp.size(), numeric_limits<uli>::min());
  dis.back() = numeric_limits<uli>::max();
  vector<bool> vis(mp.size());
  while (!q.empty()) {
    size_t p = q.top().second;
    q.pop();
    if (vis[p]) continue;
    vis[p] = true;
    for (Train const& i : mp[p]) {
      if (i.l + i.c > dis[p]) continue;
      size_t k = (dis[p] - (i.l + i.c)) / i.d;
      if (k >= i.k) k = i.k - 1;
      if (i.l + k * i.d > dis[i.a]) q.push({dis[i.a] = i.l + k * i.d, i.a});
    }
  }
  return dis;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<vector<Train>> mp(n);
  for (size_t i = 0; i < m; ++i) {
    Train t;
    cin >> t.l >> t.d >> t.k >> t.c >> t.a >> t.b;
    --t.a, --t.b;
    mp[t.b].push_back(t);
  }
  vector<uli> ans = dij(mp);
  for_each(ans.begin(), prev(ans.end()),
           [](uli x) { (x ? cout << x : cout << "Unreachable") << '\n'; });
  return 0;
}