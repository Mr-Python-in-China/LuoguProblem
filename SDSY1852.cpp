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
    cin >> n;
    map<uli, size_t> p;
    for (size_t i = 0; i < n; ++i) {
      uli x;
      cin >> x;
      ++p[x];
    }
    size_t cnt = n;
    uli ans = cnt * uli(cnt + 1) / 2;
    for (pair<uli, size_t> i : p) {
      cnt -= i.second;
      ans = min(ans, max<uli>(cnt * uli(cnt + 1) / 2, i.first));
    }
    cout << ans << '\n';
  }
  return 0;
}