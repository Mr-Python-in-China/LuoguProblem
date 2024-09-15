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
    vector<pair<ui, ui>> a(n + m + 1);
    for (pair<ui, ui> &i : a) cin >> i.first;
    for (pair<ui, ui> &i : a) cin >> i.second;
    vector<size_t> p, t;
    for (size_t i = 0; i < n + m; ++i)
      if (a[i].first > a[i].second)
        p.emplace_back(i);
      else if (a[i].first < a[i].second)
        t.emplace_back(i);
      else
        throw;
    uli sum = 0;
    if (p.size() >= n) {
      for (size_t i = 0; i < n; ++i) sum += a[p[i]].first;
      for (size_t i = n; i < p.size(); ++i) sum += a[p[i]].second;
      for (size_t i = 0; i < t.size(); ++i) sum += a[t[i]].second;
    } else {
      for (size_t i = 0; i < m; ++i) sum += a[t[i]].second;
      for (size_t i = m; i < t.size(); ++i) sum += a[t[i]].first;
      for (size_t i = 0; i < p.size(); ++i) sum += a[p[i]].first;
    }
    for (size_t i = 0; i < n + m; ++i) {
      if (a[i].first > a[i].second) {
        if (p.size() <= n)
          cout << sum - a[i].first + a.back().first << ' ';
        else if (i <= p[n])
          cout << sum - a[i].first + a[p[n]].first - a[p[n]].second +
                      a.back().second
               << ' ';
        else
          cout << sum - a[i].second + a.back().second << ' ';
      } else {
        if (t.size() <= m)
          cout << sum - a[i].second + a.back().second << ' ';
        else if (i <= t[m])
          cout << sum - a[i].second + a[t[m]].second - a[t[m]].first +
                      a.back().first
               << ' ';
        else
          cout << sum - a[i].first + a.back().first << ' ';
      }
    }
    cout << sum << '\n';
  }
  return 0;
}