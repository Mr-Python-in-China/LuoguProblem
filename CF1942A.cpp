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
    if (k == 1)
      for (size_t i = 0; i < n; ++i) cout << i + 1 << ' ';
    else if (k == n)
      for (size_t i = 0; i < n; ++i) cout << "1 ";
    else
      cout << "-1";
    cout << '\n';
  }
  return 0;
}