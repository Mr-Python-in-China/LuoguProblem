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
    uli k, x;
    cin >> n >> k >> x;
    if (n < k)
      cout << "-1\n";
    else if (x > k)
      cout << (k * (k - 1) >> 1) + (n - k) * x << '\n';
    else if (k - x == 0 || k - x == 1)
      cout << (k * (k - 1) >> 1) + (n - k) * (k - 1) << '\n';
    else
      cout << "-1\n";
  }
  return 0;
}