#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> T absm(T a, T b) { return max(a, b) - min(a, b); }
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<pair<ui, ui>> a(n);
  for (pair<ui, ui>& i : a) cin >> i.first >> i.second;
  vector<pair<ui, ui>> f(n);  // first: 从右侧出; second: 从左侧出
  f[0] = {a[0].second - 1, a[0].second - 1 + (a[0].second - a[0].first)};
  for (size_t i = 1; i < n; ++i) {
    f[i] = {min(absm(a[i - 1].second, a[i].first) + 1 + f[i - 1].first,
                absm(a[i - 1].first, a[i].first) + 1 + f[i - 1].second) +
                a[i].second - a[i].first,
            min(absm(a[i - 1].second, a[i].second) + 1 + f[i - 1].first,
                absm(a[i - 1].first, a[i].second) + 1 + f[i - 1].second) +
                a[i].second - a[i].first};
  }
  cout << min(f.back().first + (n - a.back().second),
              f.back().second + (n - a.back().first));
  return 0;
}