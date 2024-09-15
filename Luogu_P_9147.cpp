#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<size_t> a(n);
  cin >> a[0];
  vector<pair<size_t, size_t>> qj_start(1, {0, 1});
  for (size_t i = 1; i < n; i++) {
    cin >> a[i];
    if (a[i - 1] >= a[i]) qj_start.push_back({i, 0});
    qj_start.back().second++;
  }
  size_t ans = 0;
  for (pair<size_t, size_t> const& i : qj_start) ans = max(ans, i.second);
  for (vector<pair<size_t, size_t>>::const_iterator it = next(qj_start.begin());
       it < qj_start.end(); it++) {
    if ((it->first + 1 < n && a[it->first - 1] + 1 < a[it->first + 1]) ||
        a[it->first - 2] < a[it->first] - 1)
      ans = max(ans, prev(it)->second + it->second);
    else
      ans = max({ans, prev(it)->second + 1, it->second + 1});
  }
  cout << ans;
  return 0;
}