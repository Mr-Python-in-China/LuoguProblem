#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using uc = unsigned char;

struct Mod {
  uli m, p;
  void init(ui pp) {
    m = ((__int128)1 << 64) / pp;
    p = pp;
  }
  uli operator()(uli x) { return x - ((__int128(x) * m) >> 64) * p; }
} mod;

constexpr ui quick_pow(ui a, uli n, ui m) {
  uli ans = 1;
  while (n) {
    if (n & 1) ans = mod(ans *= a);
    a = mod(uli(a) * a);
    n >>= 1;
  }
  return ans;
}
constexpr uc S = 4;
constexpr uli nomod_pow10() {
  uli x = 1;
  for (uc i = 0; i < S; ++i) x *= 10;
  return x;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui a, m;
  cin >> a >> m;
  mod.init(m);
  string t;
  cin >> t;
  vector<uc> s(t.begin(), t.end());
  for (uc& i : s) i -= '0';
  reverse(s.begin(), s.end());
  while (s.size() % S != 0) s.emplace_back(0);
  reverse(s.begin(), s.end());
  vector<uli> f;
  for (size_t i = 0; i < s.size(); i += S) {
    f.emplace_back(0);
    for (size_t j = i; j < i + S; ++j) f.back() = f.back() * 10 + s[j];
  }
  ui ans = 1;
  constexpr uli bs = nomod_pow10();
  for (uli x : f) ans = mod(uli(quick_pow(ans, bs, m)) * quick_pow(a, x, m));
  cout << ans;
  return 0;
}