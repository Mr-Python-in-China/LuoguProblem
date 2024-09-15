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
    vector<vector<ui>> a(n, vector<ui>(m)), b(n, vector<ui>(m));
    for (vector<ui> &i : a)
      for (ui &j : i) cin >> j;
    for (vector<ui> &i : b)
      for (ui &j : i) cin >> j;
    {
      map<ui, size_t> first;
      for (size_t i = 0; i < n; ++i) first[b[i].front()] = i;
      vector<vector<ui>> na(n);
      for (size_t i = 0; i < n; ++i) {
        bool flag = false;
        for (ui j : a[i])
          if (first.count(j)) {
            if (flag || !na[first[j]].empty()) {
              cout << "NO\n";
              goto no;
            }
            na[first[j]] = a[i], flag = true;
          }
      }
      a = na;
    }
    {
      vector<size_t> order(m);
      {
        map<ui, size_t> mp;
        for (size_t i = 0; i < m; ++i) mp[b.front()[i]] = i;
        for (size_t i = 0; i < m; ++i) order[i] = mp[a.front()[i]];
      }
      for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
          if (a[i][j] != b[i][order[j]]) {
            cout << "NO\n";
            goto no;
          }
    }
    cout << "YES\n";
  no:;
  }
  return 0;
}