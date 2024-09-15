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
    bool flag = false;
    cin >> n;
    ui w, t;
    cin >> w >> t;
    for (size_t i = 1; i < n; ++i) {
      ui s, e;
      cin >> s >> e;
      if (s >= w && e >= t) flag = true;
    }
    (flag ? cout << "-1" : cout << w - 1) << '\n';
  }
  return 0;
}