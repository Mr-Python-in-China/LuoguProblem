#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using uli = unsigned long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<pair<ui, ui>> s(n);
    vector<vector<ui>> a(n + 1), b(n + 1);
    for (size_t i = 0; i < n; ++i) {
      ui x, y = i + 1;
      cin >> x;
      ui g = __gcd(x, y);
      s[i].first = x / g, s[i].second = y / g;
      a[s[i].first].emplace_back(i), b[s[i].second].emplace_back(i);
    }
    vector<map<ui, size_t>> c(n + 1);
    for (ui i = 1; i <= n; ++i)
      for (ui j = i; j <= n; j += i)
        for (size_t k : a[j]) ++c[i][s[k].second];
    uli cnt = 0;
    for (pair<ui, ui> const &i : s)
      for (pair<ui, size_t> const &j : c[i.second])
        if (i.first % j.first == 0) cnt += j.second;
    for (pair<ui, ui> const &i : s)
      if (i.first % i.second == 0) --cnt;
    cout << cnt / 2 << '\n';
  }
  return 0;
}