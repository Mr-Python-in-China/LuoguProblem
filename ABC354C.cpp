#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct card {
  ui a, c;
  size_t p;
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<card> a(n);
  for (size_t i = 0; i < n; ++i) a[i].p = i, cin >> a[i].a >> a[i].c;
  sort(a.begin(), a.end(), [](card const& x, card const& y) {
    return x.c == y.c ? x.a < y.a : x.c < y.c;
  });
  ui d = 0;
  vector<size_t> ans;
  for (card const& i : a)
    if (i.a >= d) d = i.a, ans.emplace_back(i.p);
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (size_t i : ans) cout << i + 1 << ' ';
  return 0;
}