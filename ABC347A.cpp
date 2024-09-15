#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui k;
  cin >> n >> k;
  for (size_t i = 0; i < n; ++i) {
    ui x;
    cin >> x;
    if (x % k == 0) cout << x / k << ' ';
  }
  return 0;
}