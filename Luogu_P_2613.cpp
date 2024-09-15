#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 19260817;
constexpr ui fast_pow(ui a, ui n) {
  ui ans = 1;
  while (n) {
    if (n & 1) ans = uli(ans) * a % P;
    a = uli(a) * a % P;
    n >>= 1;
  }
  return ans;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui a = 0, b = 0;
  {
    string s, t;
    cin >> s >> t;
    for (char c : s) ((a *= 10) += c - '0') %= P;
    for (char c : t) ((b *= 10) += c - '0') %= P;
  }
  cout << uli(a) * fast_pow(b, P - 2) % P;
  return 0;
}