#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 998244353;
constexpr ui fastpow(ui a, ui n) {
  uli ans = 1;
  while (n) {
    if (n & 1) (ans *= a) %= P;
    a = uli(a) * a % P;
    n >>= 1;
  }
  return ans;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    string t;
    size_t n;
    cin >> t >> n;
    ui a = 0, b = 0;
    for (char i : t) b += i == '?';
    while (n--) {
      string s;
      cin >> s;
      for (size_t i = 0; i + s.size() <= t.size(); ++i) {
        for (size_t j = 0; j < s.size(); ++j)
          if (t[i + j] != '?' && s[j] != t[i + j]) goto out;
        ++a;
      out:;
      }
    }
    cout << uli(a) * fastpow(fastpow(26, b), P - 2) % P;
  }
  return 0;
}