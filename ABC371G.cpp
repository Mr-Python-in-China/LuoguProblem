#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T, typename F> T& fastPow(T a, uli n, T& ans, F const& f) {
  while (n) {
    if (n & 1) ans = f(ans, a);
    a = f(a, a);
    n >>= 1;
  }
  return ans;
}
const auto tf = [](vector<size_t> const& a, vector<size_t> const& x) {
  vector<size_t> res(a.size());
  for (size_t i = 0; i < a.size(); ++i) res[x[i]] = a[i];
  return res;
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  fin >> n;
  vector<size_t> a(n), p(n);
  for (size_t& i : a) fin >> i, --i;
  for (size_t& i : p) fin >> i, --i;
  vector<size_t> group(n, ~0);
  size_t groupCount = 0;
  for (size_t i = 0; i < n; ++i)
    if (!~group[i]) {
      group[i] = groupCount++;
      for (size_t j = p[i]; j != i; j = p[j]) group[j] = group[i];
    }
  vector<vector<size_t>> groupMember(groupCount);
  for (size_t i = 0; i < n; ++i) groupMember[group[i]].emplace_back(i);
  size_t gcd = 0, mod = 0;
  for (vector<size_t> const& g : groupMember) {
    gcd = __gcd(gcd, g.size());
    mod %= gcd;
    unordered_map<size_t, size_t> mapper;
    for (size_t i = 0; i < g.size(); ++i) mapper[g[i]] = i;
    vector<size_t> gp(g.size());
    for (size_t i = 0; i < gp.size(); ++i) gp[i] = mapper.at(p[g[i]]);
    vector<size_t> gtd(g.size());
    iota(gtd.begin(), gtd.end(), 0);
    fastPow(gp, gcd, gtd, tf);
    vector<size_t> color(g.size(), ~0);
    size_t colorCnt = 0;
    for (size_t i = 0; i < g.size(); ++i)
      if (!color[i]) {
        color[i] = colorCnt++;
        for (size_t j = gtd[i]; j != i; j = gtd[j]) color[j] = color[i];
      }
    assert(colorCnt == g.size() / gcd);
    
    vector<size_t> ncl(color);
    for (size_t i=0;i<mod;++i) ncl=tf(ncl,gp);
    size_t bestColor=ncl[0];
    size_t minx=numeric_limits<size_t>::max();
    for (size_t i=0;i<g.size();++i) if (color[i]==bestColor) minx=min(minx,a[i]);
    
  }
  return 0;
}