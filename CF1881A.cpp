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
    size_t n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    size_t ans = 0;
    for (; ans < 6; ++ans, s += s)
      if (~s.find(t)) break;
    cout << int(ans < 6 ? ans : -1) << '\n';
  }
  return 0;
}