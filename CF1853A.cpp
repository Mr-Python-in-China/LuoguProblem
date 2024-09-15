#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    int lst;
    int minminus = 0x7fffffff;
    cin >> n >> lst;
    while (--n) {
      int now;
      cin >> now;
      minminus = min(now - lst, minminus);
      lst = now;
    }
#ifdef debug
    cout << minminus << ' ';
#endif
    cout << (minminus >= 0 ? (minminus + 2) >> 1 : 0) << '\n';
  }
  return 0;
}