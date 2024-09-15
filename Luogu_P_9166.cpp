#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, x;
  cin >> n >> m >> x;
  --x;
  vector<pair<size_t, size_t>> a(m);
  for (pair<size_t, size_t>& i : a)
    cin >> i.first >> i.second, --i.first, --i.second;
  vector<size_t> ans;
  {
    vector<vector<size_t>> f(n);
    vector<bool> isend(n);
    size_t maxdis = x;
    for (pair<size_t, size_t> const& i : a) {
      f[i.first].push_back(i.second), isend[i.second] = true;
      if (i.first <= x && x <= i.second) maxdis = max(maxdis, i.second);
    }
    if (maxdis > x)
      for (size_t i = x + 1; i <= maxdis; ++i) {
        for (size_t j : f[i]) maxdis = max(maxdis, j);
        if (isend[i]) ans.push_back(i);
      }
  }
  {
    vector<vector<size_t>> f(n);
    vector<bool> isstart(n);
    size_t mindis = x;
    for (pair<size_t, size_t> const& i : a) {
      f[i.second].push_back(i.first), isstart[i.first] = true;
      if (i.first <= x && x <= i.second) mindis = min(mindis, i.first);
    }
    if (mindis < x)
      for (size_t i = x - 1; i >= mindis && i < n; --i) {
        for (size_t j : f[i]) mindis = min(mindis, j);
        if (isstart[i]) ans.push_back(i);
      }
  }
  sort(ans.begin(), ans.end());
  for (size_t i : ans) cout << i + 1 << ' ';
  return 0;
}