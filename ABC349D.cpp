#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> T lowbit(T x) { return x & -x; }
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli x, y;
  cin >> x >> y;
  uli i = x, j;
  vector<pair<uli, uli>> ans;
  if (x != 0)
    for (j = x + lowbit(x); j < y; i = j, j += lowbit(j))
      ans.emplace_back(i, j);
  j = i;
  uli k = uli(1) << uli(63);
  while (j < y) {
    while (j + k > y) k >>= 1;
    i = j, j = j + k;
    ans.emplace_back(i, j);
  }
  cout << ans.size() << '\n';
  for (pair<uli, uli> const& a : ans)
    cout << a.first << ' ' << a.second << '\n';
  return 0;
}