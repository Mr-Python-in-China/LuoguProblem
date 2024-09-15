#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n, b, d;
  cin >> n >> b >> d;
  vector<ui> ans;
  for (ui i = 0; ans.size() < n; ++i) {
    for (ui j : ans)
      if (__builtin_popcount(j ^ i) < d) goto failed;
    ans.push_back(i);
  failed:;
  }
  ui t = 0;
  for (ui i : ans) {
    cout << i << ' ';
    if (++t == 10) t = 0, cout.put('\n');
  }
  return 0;
}