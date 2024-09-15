#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    ui x;
    cin >> n >> x;
    vector<ui> a(n);
    for (ui& i : a) cin >> i;
    ui ans = a.front();
    for (vector<ui>::iterator it = next(a.begin()); it < a.end(); ++it)
      ans = max(ans, *it - *prev(it));
    ans = max(ans, (x - a.back()) << 1);
    for (vector<ui>::reverse_iterator it = next(a.rbegin()); it < a.rend();
         ++it)
      ans = max(ans, *prev(it) - *it);
    cout << ans << '\n';
  }
  return 0;
}