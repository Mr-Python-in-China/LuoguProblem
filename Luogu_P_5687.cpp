#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct edge {
  uli v;
  bool type;
  size_t pos;
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  deque<edge> a(n + m);
  for (size_t i = 0; i < n; ++i) cin >> a[i].v, a[i].type = false, a[i].pos = i;
  for (size_t i = 0; i < m; ++i)
    cin >> a[i + n].v, a[i + n].type = true, a[i + n].pos = i;
  sort(a.begin(), a.end(),
       [](edge const& a, edge const& b) { return a.v < b.v; });
  size_t sc = 0, tc = 0;
  uli cnt = n * m - 1, ans = 0;
  while (cnt) {
    edge& now = a.front();
    size_t tr = min<size_t>(cnt, now.type   ? sc && tc ? n - sc : n - 1
                                 : tc && sc ? m - tc
                                            : m - 1);
    ans += tr * now.v, cnt -= tr;
    ++(now.type ? tc : sc);
    a.pop_front();
  }
  cout << ans;
  return 0;
}