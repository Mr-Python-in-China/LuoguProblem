#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, d;
  cin >> n >> d;
  vector<ui> a(n);
  for (ui& i : a)
    for (ui j = 0; j < d; ++j) {
      char c;
      cin >> c;
      (i <<= 1) |= c == '1';
    }
  for (ui i : a) {
    ui ans = 0;
    for (ui j : a) ans = max<ui>(ans, __builtin_popcount(i ^ j));
    cout << ans << '\n';
  }
  return 0;
}