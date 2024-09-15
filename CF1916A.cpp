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
    size_t n, k;
    cin >> n >> k;
    uli t = 1;
    for (size_t i = 0; i < n; ++i) {
      uli x;
      cin >> x;
      t *= x;
    }
    if (2023 % t)
      cout << "NO\n";
    else {
      cout << "YES\n" << 2023 / t << ' ';
      for (size_t i = 1; i < k; ++i) cout << "1 ";
      cout.put('\n');
    }
  }
  return 0;
}