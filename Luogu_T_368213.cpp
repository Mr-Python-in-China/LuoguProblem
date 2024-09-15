#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (pair<int, int>& i : a) cin >> i.first >> i.second;
    sort(a.begin(), a.end());
    int l = 0, r = 1e9 + 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      vector<pair<int, int>>::iterator line =
          lower_bound(a.begin(), a.end(), pair<int, int>(mid, 0));
      vector<pair<int, int>> able(line, a.end()), unable(a.begin(), line);
      sort(able.begin(), able.end(),
           [](pair<int, int> const& a, pair<int, int> const& b) {
             return a.first + a.second < b.first + b.second;
           });
      sort(unable.begin(), unable.end(),
           [](pair<int, int> const& a, pair<int, int> const& b) {
             return a.second < b.second;
           });
      bool flag = true;
      for (vector<pair<int, int>>::reverse_iterator it = unable.rbegin(),
                                                    jt = able.rbegin();
           it < unable.rend(); it++, jt++) {
        if (jt >= able.rend() || jt->first - (it->second - jt->second) < mid) {
          flag = false;
          break;
        }
      }
      if (flag)
        l = mid;
      else
        r = mid - 1;
    }
    cout << l << '\n';
  }
  return 0;
}