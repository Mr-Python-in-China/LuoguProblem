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
    size_t n, m, k;
    cin >> n >> m >> k;
    cout << (n - ((n + m - 1) / m) <= k ? "NO\n" : "YES\n");
  }
  return 0;
}