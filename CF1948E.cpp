#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    usi n, k;
    cin >> n >> k;
    vector<usi> a(n, ~0);
    vector<usi> b(n);
    size_t lst = n;
    usi c = 0;
    for (size_t d; n -= d = min(n, k), d; lst = n, ++c) {
      for (size_t i = n; i < (lst + n) / 2; ++i)
        a[i] = i - n + (lst + n + 1) / 2 + 1, b[i] = c + 1;
      for (size_t i = (lst + n) / 2; i < lst; ++i)
        a[i] = (i - (lst + n) / 2) + n + 1, b[i] = c + 1;
    }
    for (usi i : a) cout << i << ' ';
    cout << '\n' << c << '\n';
    for (usi i : b) cout << i << ' ';
    cout << '\n';
  }
  return 0;
}