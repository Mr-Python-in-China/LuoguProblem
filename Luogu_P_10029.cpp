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
    ui n, m, p;
    cin >> n >> m >> p;
    ui nn = n, nm = m;
    do {
      n = nn, m = nm;
      nm = m - m % p;
      if (nm == 0) {
        cout << "Alice\n";
        goto out;
      }
      nn = n - n % p;
      if (nn == 0) {
        cout << "Bob\n";
        goto out;
      }
    } while (n != nn || m != nm);
    cout << "Lasting Battle\n";
  out:;
  }
  return 0;
}