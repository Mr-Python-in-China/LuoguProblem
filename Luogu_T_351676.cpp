#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using uli = unsigned long long int;
using graph = vector<vector<size_t>>;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  graph mp(n);
  for (size_t i = 1; i < n; i++) {
    size_t u, v;
    cin >> u >> v;
    --u, --v;
    mp[u].push_back(v), mp[v].push_back(u);
  }
  vector<uli> dis(n);
  dis[0] = 1;
  size_t cnt = 0;
  queue<size_t> q({0});
  while (!q.empty()) {
    size_t p = q.front();
    q.pop();
    for (size_t const& j : mp[p])
      if (!dis[j]) dis[j] = dis[p] + 1, q.push(j);
  }
  uli halfsum = accumulate(dis.begin(), dis.end(), uli(0));
  if (halfsum & 1) return cout << "-1", 0;

  vector<vector<uli>::const_iterator> its(n);
  halfsum >>= 1;
  iota(its.begin(), its.end(), dis.begin());
  sort(its.begin(), its.end(),
       [](vector<uli>::const_iterator const& a,
          vector<uli>::const_iterator const& b) { return *a < *b; });
  uli ans = 0;
  vector<bool> used(n);
  for (vector<vector<uli>::const_iterator>::const_reverse_iterator it =
           its.crbegin();
       it != its.crend(); it++) {
    if (halfsum - ans < **it) break;
    ans += **it;
    used[*it - dis.begin()] = true;
  }
  if (halfsum - ans > 0) {
    vector<vector<uli>::const_iterator>::const_iterator it =
        lower_bound(its.begin(), its.end(), halfsum - ans,
                    [](vector<uli>::const_iterator const& a, uli const& b) {
                      return *a < b;
                    });
    used[*it - dis.begin()] = true;
  }
  for (size_t i = 0; i < n; i++)
    cout << !used[i] << ' '
#ifdef debug
         << flush
#endif
        ;
  return 0;
}