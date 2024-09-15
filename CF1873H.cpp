#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<vector<size_t>>;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, a, b;
    cin >> n >> a >> b;
    --a, --b;
    graph mp(n);
    for (size_t i = 0; i < n; ++i) {
      size_t u, v;
      cin >> u >> v;
      --u, --v;
      mp[u].push_back(v), mp[v].push_back(u);
    }
    size_t dist_a = 0, dist_b = 0;
    size_t point;
    {
      vector<bool> on_ring(n);
      size_t s, t;
      queue<size_t> q({b});
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
      point = i;
      i = pre[i];
      for (; ~i; i = pre[i], ++dist_b) on_ring[i] = false;
    }
    {
      queue<size_t> q({a});
      vector<bool> vis(n, true);
      while (!q.empty()) {
        for (size_t I = q.size(); I; --I) {
          size_t p = q.front();
          q.pop();
          if (p == point) goto out2;
          for (size_t const& i : mp[p])
            if (vis[i]) q.push(i), vis[i] = false;
        }
        ++dist_a;
      }
      throw;
    out2:;
    }
#ifdef debug
    cout << "\033[31m" << dist_a << ' ' << dist_b << "\033[0m";
#endif
    cout << (dist_a > dist_b ? "YES" : "NO") << '\n';
  }
  return 0;
}