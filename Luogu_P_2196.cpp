#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<vector<size_t>>;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<ui> v(n);
  for (ui& i : v) cin >> i;
  graph mp(n);
  for (size_t i = 0; i < n; ++i)
    for (size_t j = i + 1; j < n; ++j) {
      bool b;
      cin >> b;
      if (b) mp[j].push_back(i);
    }
  vector<ui> f(n);
  vector<size_t> from(n, -1);
  size_t ansp = 0;
  for (size_t i = 0; i < n; ++i) {
    for (size_t j : mp[i])
      if (f[j] > f[i]) f[i] = f[j], from[i] = j;
    f[i] += v[i];
    if (f[i] > f[ansp]) ansp = i;
  }
  vector<size_t> stk;
  for (size_t i = ansp; i != -1; i = from[i]) stk.push_back(i);
  for_each(stk.rbegin(), stk.rend(), [](size_t i) { cout << i + 1 << ' '; });
  cout << '\n' << f[ansp];
  return 0;
}