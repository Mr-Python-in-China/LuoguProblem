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
    list<ui> a(n);
    for (ui& i : a) cin >> i;
    bool flag;
    do {
      flag = false;
      bool odd = a.size() & 1;
      for (list<ui>::reverse_iterator it = a.rbegin(); it != a.rend(); odd ^= 1)
        if (*it >= 0)
          a.erase((++it).base());
        else
          ++it;
    } while (flag);
    for (ui const& i : a) cout << i << ' ';
    cout << '\n';
  }
  return 0;
}