#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> T abs_minus(T const& a, T const& b) {
  return max(a, b) - min(a, b);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<ui> a(n), b(n + 1);
    for (ui& i : a) cin >> i;
    for (ui& i : b) cin >> i;
    uli ans = 0;
    bool flag = false;
    for (size_t i = 0; i < n; ++i) {
      ans += abs_minus(a[i], b[i]);
      if (!flag && min(a[i], b[i]) <= b.back() && b.back() <= max(a[i], b[i]))
        ++ans, flag = true;
    }
    auto cmp = [&b](ui x, ui y) {
      return abs_minus(x, b.back()) < abs_minus(y, b.back());
    };
    if (!flag)
      ans += abs_minus(min(*min_element(a.begin(), a.end(), cmp),
                           *min_element(b.begin(), b.end() - 1, cmp), cmp),
                       b.back()) +
             1;
    cout << ans << '\n';
  }
  return 0;
}