#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  ui k;
  cin >> n >> m >> k;
  list<size_t> a(n);
  vector<ui> t(n);
  for (size_t& i : a) cin >> i, ++t[--i];
  for (ui& i : t) i = min(i, k);
  ui ans = 0, enb = 0;
  list<size_t>::iterator jt = a.begin();
  vector<ui> cnt(n);
  for (size_t i = 0; i < n; ++i) {
    while (jt != a.end() && enb < m) {
      if (cnt[*jt]++ == 0) {
        ++enb;
        ans += t[*jt];
      }
      ++jt;
    }
    cout << ans << '\n';
    if (--cnt[a.front()] == 0) --enb, ans -= t[a.front()];
    a.push_back(a.front()), a.pop_front();
  }
  return 0;
}