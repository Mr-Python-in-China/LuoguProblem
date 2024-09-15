#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using Graph = vector<vector<size_t>>;
pair<size_t, size_t> sol(Graph const& mp, size_t g, size_t& k, size_t p,
                         size_t fa = ~0) {
  size_t sz = 1, ans = ~0;
  for (size_t i : mp[p])
    if (i != fa) {
      pair<size_t, size_t> res = sol(mp, g, k, i, p);
      if (res.first >= g && k)
        ans = min(ans, res.first), --k;
      else
        sz += res.first, ans = min(ans, res.second);
    }
  return {sz, ans};
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, k;
    cin >> n >> k;
    Graph mp(n);
    for (size_t i = 1; i < n; ++i) {
      size_t x, y;
      cin >> x >> y;
      --x, --y;
      mp[x].push_back(y), mp[y].push_back(x);
    }
    size_t l = 1, r = n;
    auto f = [&](size_t mid) {
      size_t x = k;
      auto res = sol(mp, mid, x, 0);
      if (res.first) res.second = min(res.second, res.first);
      return x == 0 && res.second >= mid;
    };
    while (l < r) {
      size_t mid = (l + r + 1) / 2;
      f(mid) ? l = mid : r = mid - 1;
    }
    cout << l << '\n';
  }
  return 0;
}