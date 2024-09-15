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
    size_t n;
    cin >> n;
    vector<usi> k(n);
    for (usi &i : k) cin >> i;
    uli l = k[0];
    for (usi i : k) l = (l * i) / __gcd<uli>(l, i);
    uli s = 0;
    for (usi i : k) s += l / i;
    if (s >= l)
      cout << "-1\n";
    else {
      uli l = k[0];
      for (usi i : k) l = (l * i) / __gcd<uli>(l, i);
      for (usi i : k) cout << (l / i) << ' ';
      cout << '\n';
    }
  }
  return 0;
}