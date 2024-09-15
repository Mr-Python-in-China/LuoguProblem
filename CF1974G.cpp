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
    size_t m;
    ui x;
    cin >> m >> x;
    ui d = 0;
    priority_queue<ui> q;
    for (size_t i = 0; i < m; ++i) {
      ui c;
      cin >> c;
      if (c <= d)
        d -= c, q.push(c);
      else if (!q.empty()) {
        ui t = q.top();
        if (c < t) q.pop(), d += t, d -= c, q.push(c);
      }
      d += x;
    }
    cout << q.size() << '\n';
  }
  return 0;
}