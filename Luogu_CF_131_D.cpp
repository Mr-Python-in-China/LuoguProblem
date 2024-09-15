#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<vector<size_t>>;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  graph mp(n);
  for (size_t i = 0; i < n; ++i) {
    size_t u, v;
    cin >> u >> v;
    --u, --v;
    mp[u].push_back(v), mp[v].push_back(u);
  }
  vector<bool> on_ring(n);
  {
    size_t s, t;
    queue<size_t> q({0});
    vector<size_t> pre(n, -1);
    while (!q.empty()) {
      size_t p = q.front();
      q.pop();
      for (size_t const& i : mp[p])
        if (pre[p] != i)
          if (~pre[i]) {
            s = i, t = p;
            goto out1;
          } else
            q.push(i), pre[i] = p;
    }
    throw;
  out1:;
    for (size_t i = s; ~i; i = pre[i]) on_ring[i] = true;
    size_t i = t;
    for (; ~i && !on_ring[i]; i = pre[i]) on_ring[i] = true;
    i = pre[i];
    for (; ~i; i = pre[i]) on_ring[i] = false;
  }
  return 0;
}