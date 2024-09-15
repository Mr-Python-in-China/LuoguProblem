#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 2147483587;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string s;
  ui k;
  cin >> s;
  array<bool, 26> bad;
  for (bool& i : bad) {
    char c;
    cin >> c;
    i = c == '0';
  }
  cin >> k;
  unordered_set<ui> vis;
  ui ans = 0;
  for (size_t i = 0; i < s.size(); ++i) {
    ui h = 0;
    ui c = 0;
    for (size_t j = i; j < s.size(); ++j) {
      h = (h * uli(128) + s[j]) % P;
      if (bad[s[j] - 'a']) ++c;
      if (vis.insert(h).second && c <= k) ++ans;
    }
  }
  cout << ans;
  return 0;
}