#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using uli = unsigned long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    uli n, m;
    cin >> n >> m;
    cout << 2 - (((n | m) == m) + ((n | m) == n)) << '\n';
  }
  return 0;
}