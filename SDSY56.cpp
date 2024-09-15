#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui b;
  cin >> n >> b;
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  size_t bp = find(a.begin(), a.end(), b) - a.begin();
  vector<int> f(n + 1);
  for (size_t i = 0; i < n; ++i)
    f[i + 1] = f[i] + (a[i] > b ? 1 : a[i] < b ? -1 : 0);
  array<unordered_map<int, ui>, 2> cnt;
  for (size_t i = bp; i < n; ++i) ++cnt[i & 1][f[i + 1]];
  uli ans = 0;
  for (size_t i = 0; i <= bp + 1; ++i) ans += cnt[i & 1][f[i]];
  cout << ans;
  return 0;
}