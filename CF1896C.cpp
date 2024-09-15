#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, m;
    cin >> n >> m;
    vector<pair<ui, size_t>> a(n), b(n);
    for (size_t i = 0; i < n; ++i) cin >> a[i].first, a[i].second = i;
    for (size_t i = 0; i < n; ++i) cin >> b[i].first;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<pair<ui, size_t>> c(b.begin(), b.begin() + m);
    b.erase(b.begin(), b.begin() + m);
    b.insert(b.end(), c.begin(), c.end());
    for (size_t i = 0; i < n; ++i) b[i].second = a[i].second;
    sort(a.begin(), a.end(),
         [](pair<ui, size_t> const& a, pair<ui, size_t> const& b) {
           return a.second < b.second;
         }),
        sort(b.begin(), b.end(),
             [](pair<ui, size_t> const& a, pair<ui, size_t> const& b) {
               return a.second < b.second;
             });
    size_t cnt = 0;
    for (size_t i = 0; i < n; ++i) cnt += a[i].first > b[i].first;
    if (cnt == m) {
      cout << "YES\n";
      for (size_t i = 0; i < n; ++i) cout << b[i].first << ' ';
      cout << '\n';
    } else
      cout << "NO\n";
  }
  return 0;
}