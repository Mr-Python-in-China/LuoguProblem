#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 2147483647;
constexpr ui fastpow(ui a, ui n) {
  ui ans = 1;
  while (n) {
    if (n & 1) ans = uli(ans) * a % P;
    a = uli(a) * a % P;
    n >>= 1;
  }
  return ans;
}
ui pow_128(ui n) {
  static array<ui, size_t(1e6 + 1)> mem = {};
  if (mem[n]) return mem[n];
  if (n == 0) return mem[n] = 1;
  return mem[n] = uli(pow_128(n - 1)) * 128 % P;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  string ans;
  while (n--) {
    string s;
    cin >> s;
    size_t l = 0, r = min(ans.size(), s.size());
    size_t t = -1;
    ui ha = 0, hs = 0;
    for (size_t i = 0; i < min(s.size(), ans.size()); ++i) {
      ha = (ha + pow_128(i) * uli(ans.rbegin()[i])) % P,
      hs = (hs * uli(128) + s[i]) % P;
      if (ha == hs) t = i;
    }
    ans.insert(ans.end(), s.begin() + ++t, s.end());
  }
  cout << ans;
  return 0;
}