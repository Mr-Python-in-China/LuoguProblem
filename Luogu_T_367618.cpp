#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using lli = __int128_t;
using graph = vector<vector<pair<size_t, lli>>>;
constexpr lli P = 998244353;
size_t get_childtree_dissum(graph const& mp, vector<size_t>& sz, size_t p,
                            size_t fa = -1) {
  sz[p] = 1;
  size_t ans = 0;
  for (pair<size_t, lli> const& i : mp[p])
    if (i.first != fa) {
      (ans +=
       get_childtree_dissum(mp, sz, i.first, p) + i.second * sz[i.first]) %= P;
      sz[p] += sz[i.first];
    }
  return ans;
}
void get_dissum(graph const& mp, vector<lli>& ans, vector<size_t> const& sz,
                size_t p, size_t fa = -1) {
  for (pair<size_t, lli> const& i : mp[p])
    if (i.first != fa) {
      ans[i.first] = ((ans[p] - i.second * sz[i.first] +
                       i.second * (sz[0] - sz[i.first])) %
                          P +
                      P) %
                     P;
      get_dissum(mp, ans, sz, i.first, p);
    }
}
istream& operator>>(istream& in, lli& x) {
  unsigned long long int tmp;
  in >> tmp;
  x = tmp;
  return in;
}
ostream& operator<<(ostream& out, lli x) {
  return out << (unsigned long long int)x;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, q;
  cin >> n >> q;
  graph mp(n);
  for (size_t i = 1; i < n; i++) {
    size_t u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    mp[u].push_back({v, w}), mp[v].push_back({u, w});
  }
  vector<size_t> sz(n);
  vector<lli> dissum(n);
  dissum[0] = get_childtree_dissum(mp, sz, 0);
  get_dissum(mp, dissum, sz, 0);
  lli sumdis = accumulate(dissum.cbegin(), dissum.cend(), lli(0)) % P;
  while (q--) {
    size_t x;
    lli w;
    cin >> x >> w;
    --x;
    cout << (sumdis + 2 * (dissum[x] + w * n)) % P << '\n';
  }
  return 0;
}