#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli n, m;
  cin >> n >> m;
  uli ans = 0;
  for (uli i = 0; i < 64; ++i) {
    if (((m >> i) & 1))
      (ans += (n >> i >> 1ull << i) +
              (n & (1ull << i) ? (n & (i ? (1ull << i) - 1ull : 0)) + 1ull
                               : 0)) %= 998244353;
  }
  cout << ans;
  return 0;
}