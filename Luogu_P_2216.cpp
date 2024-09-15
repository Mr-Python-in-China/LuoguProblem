#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, k;
  cin >> n >> m >> k;
  vector<vector<ui>> a(n, vector<ui>(m));
  for (vector<ui>& i : a)
    for (ui& j : i) cin >> j;
  vector<vector<size_t>> xa(n), na(n);
  for (size_t i = 0; i < n; ++i) {
    deque<size_t> qx, qn;
    for (size_t j = 0; j < m; ++j) {
      if (!qx.empty() && j - qx.front() >= k) qx.pop_front();
      while (!qx.empty() && a[i][qx.back()] <= a[i][j]) qx.pop_back();
      qx.push_back(j);
      if (j >= k - 1) xa[i].push_back(qx.front());

      if (!qn.empty() && j - qn.front() >= k) qn.pop_front();
      while (!qn.empty() && a[i][qn.back()] >= a[i][j]) qn.pop_back();
      qn.push_back(j);
      if (j >= k - 1) na[i].push_back(qn.front());
    }
  }
  vector<vector<size_t>> na(m - k + 1), nb(m - k + 1);
  for (size_t i = 0; i < m - k + 1; ++i) {
    deque<size_t> qx, qn;
    for (size_t j = 0; j < n; ++j) {
      if (!qx.empty() && j - qx.front() >= k) qx.pop_front();
      while (!qx.empty() && a[]) }
  }
  return 0;
}
