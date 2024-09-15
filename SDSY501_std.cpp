#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui x;
  cin >> n >> x;
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  uli ans = 0;
  for (vector<ui>::const_iterator it = a.begin(); it < a.end(); ++it)
    for (vector<ui>::const_iterator jt = it; jt < a.end(); ++jt) {
      vector<ui> d(it, next(jt));
      sort(d.begin(), d.end());
      if (max(d[d.size() / 2], d[(d.size() - 1) / 2]) >= x) ++ans;
    }
  cout << ans;
  return 0;
}