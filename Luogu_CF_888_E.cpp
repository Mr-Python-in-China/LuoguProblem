#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
void dfs(vector<ui>::const_iterator begin, vector<ui>::const_iterator end,
         uli v, set<ui>& ans, ui m) {
  if (begin == end)
    ans.insert(v % m);
  else
    dfs(next(begin), end, v, ans, m), dfs(next(begin), end, v + *begin, ans, m);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui m;
  cin >> n >> m;
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  random_shuffle(a.begin(), a.end());
  set<ui> ans1, ans2;
  dfs(a.begin(), a.begin() + n / 2, 0, ans1, m),
      dfs(a.begin() + n / 2, a.end(), 0, ans2, m);
  ui ans = 0;
  for (ui i : ans1) {
    set<ui>::iterator it = ans2.lower_bound(m - i);
    ans = max(ans, (it == ans2.begin() ? 0 : *prev(it)) + i);
  }
  cout << ans;
  return 0;
}