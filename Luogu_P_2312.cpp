#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 1e9 + 7;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui m;
  cin >> n >> m;
  vector<ui> a(n + 1);
  for (ui& i : a) {
    string s;
    cin >> s;
    bool flag = false;
    if (s.front() == '-') s.erase(0, 1), flag = true;
    for (char j : s) i = (i * 10ll + j - '0') % P;
    if (flag) i = (P - i) % P;
  }
  vector<ui> ans;
  for (ui x = 1; x <= m; ++x) {
    ui sum = 0;
    for (ui c = 0, p = 1; c <= n; ++c, p = uli(x) * p % P)
      sum = (sum + uli(p) * a[c]) % P;
    if (sum == 0) ans.emplace_back(x);
  }
  cout << ans.size() << '\n';
  for (ui i : ans) cout << i << '\n';
  return 0;
}