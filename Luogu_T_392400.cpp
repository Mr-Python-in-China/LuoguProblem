#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
ui constexpr P = 998244353;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui w;
  cin >> n >> w;
  vector<ui> pr;
  {
    ui x = w, i = 2;
    for (; i * i < w; ++i)
      while (x % i == 0) pr.push_back(i), x /= i;
    if (i * i == x) pr.push_back(i), x /= i;
    assert(x == 1);
  }
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  for (ui const i : pr) {
    for (ui& j : a)
      if (j % i != 0) {
        j *= i;
        goto out;
      }
    a[0] *= i;
  out:;
  }
#ifdef debug
  for (ui i : a) cout << i << ' ';
#endif
  uli ans = 1;
  for (ui i : a) {
    ui j = 1, cnt = 0;
    for (; j * j < i; ++j)
      if (i % j == 0) cnt += 2;
    if (j * j == i) ++cnt;
    (ans *= cnt) %= P;
  }
  cout << ans;
  return 0;
}