#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<size_t> a(m);
  for (size_t& i : a) cin >> i;
  vector<vector<size_t>> v(m, vector<size_t>(n));
  for (vector<size_t>& i : v)
    for (size_t& j : i) cin >> j, --j;
  vector<bool> choose(n);
  for (size_t i = 0; i < n; ++i) {
    choose[i] = true;
    vector<bool> done(n);
    size_t leave_time = 0, lst = 0;
    for (size_t j = 0; j < m; ++j) {
      leave_time += a[j] - lst;
      size_t k = 0;
      for (; choose[v[j][k]] || done[v[j][k]]; ++k)
        if (!done[v[j][k]])
          if (leave_time == 0) {
            choose[i] = false;
            goto NO;
          } else
            --leave_time, done[v[j][k]] = true;
      done[v[j][k]] = true;
      lst = a[j];
    }
  NO:;
  }
  vector<bool> ans(choose);
  {
    vector<bool> done(n);
    size_t leave_time = 0, lst = 0;
    for (size_t j = 0; j < m; ++j) {
      leave_time += a[j] - lst;
      size_t k = 0;
      for (; choose[v[j][k]] || done[v[j][k]]; ++k)
        if (!done[v[j][k]])
          if (leave_time == 0)
            throw;
          else
            --leave_time, done[v[j][k]] = true, cout << v[j][k] + 1 << ' ',
                          ans[v[j][k]] = false;
      done[v[j][k]] = true;
      lst = a[j];
    }
    for (size_t i = 0; i < n; ++i)
      if (ans[i]) cout << i + 1 << ' ';
  }
  return 0;
}