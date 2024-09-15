#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  multimap<ui, size_t> h;
  for (size_t i = 0; i < n; ++i) h.emplace(a[i], i);
  ui d = *max_element(a.begin(), a.end());
  vector<ui> blks;
  {
    blks.push_back(1);
    multimap<size_t, size_t> invs{
        {0, n}
    };
    for (ui j = 1; !invs.empty(); ++j) {
      blks.push_back(invs.size());
      auto it = h.lower_bound(j), jt = h.lower_bound(j + 1);
      for (auto kt = it; kt != jt; ++kt) {
        auto invt = prev(invs.upper_bound(kt->second));
        if (kt->second > invt->first) invs.emplace(invt->first, kt->second);
        if (kt->second + 1 < invt->second)
          invs.emplace(kt->second + 1, invt->second);
        invs.erase(invt);
      }
    }
  }
  for (ui i = 1; i <= d; ++i) {
    uli ans = 0;
    for (ui j = 1; j <= d; j += i) ans += blks[j];
    cout << ans << ' ';
  }
  return 0;
}