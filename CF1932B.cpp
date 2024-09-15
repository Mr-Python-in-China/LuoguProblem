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
    uli lst;
    cin >> lst;
    for (size_t i = 2; i <= n; ++i) {
      uli a;
      cin >> a;
      lst = (lst + a) / a * a;
    }
    cout << lst << '\n';
  }
  return 0;
}