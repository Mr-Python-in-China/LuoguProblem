#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<vector<size_t>>;
uli get_childtree_dissum(graph const& mp, vector<uli> const& v, vector<uli>& vs,
                         size_t p, size_t fa = -1) {
  vs[p] = v[p];
  uli ans = 0;
  for (size_t i : mp[p])
    if (i != fa) {
      ans += get_childtree_dissum(mp, v, vs, i, p);
      ans += vs[i];
      vs[p] += vs[i];
    }
  return ans;
}
void get_dissum(graph const& mp, vector<uli>& ans, vector<uli> const& vs,
                size_t p, size_t fa = -1) {
  for (size_t i : mp[p])
    if (i != fa) {
      ans[i] = ans[p] - vs[i] + (vs[0] - vs[i]);
      get_dissum(mp, ans, vs, i, p);
    }
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  graph mp(n);
  for (size_t i = 1; i < n; ++i) {
    size_t x, y;
    cin >> x >> y;
    --x, --y;
    mp[x].emplace_back(y), mp[y].emplace_back(x);
  }
  vector<uli> v(n);
  for (uli& i : v) cin >> i;
  vector<uli> ans(n), vs(n);
  ans[0] = get_childtree_dissum(mp, v, vs, 0);
  get_dissum(mp, ans, vs, 0);
  cout << *min_element(ans.cbegin(), ans.cend());
  return 0;
}