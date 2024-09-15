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
  vector<ui> a(m);
  for (ui& i : a) cin >> i;
  if (count(a.begin(), a.end(), 1) || count(a.begin(), a.end(), n))
    return cout << "-1", 0;
  sort(a.begin(), a.end());
  vector<ui> ans(n);
  iota(ans.begin(), ans.end(), ui(1));
  for (ui i : a) swap(ans[i - 1], ans[i]);
  for (ui i : ans) cout << i << ' ';
  return 0;
}