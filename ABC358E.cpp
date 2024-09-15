#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
constexpr ui P = 998244353;
constexpr uli undefined = ~0;
ui C(ui x, ui y) {
  static array<array<ui, 1001>, 1001> mem = {};
  if (mem[x][y]) return mem[x][y];
  if (x < y) return 0;
  if (y == 0 || y == x) return mem[x][y] = 1;
  return mem[x][y] = (C(x, y - 1) + C(x - 1, y)) % P;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  usi k;
  cin >> k;
  array<usi, 26> c;
  for (usi &i : c) cin >> i;
  vector<ui> f(k + 1, 0);
  f[0] = 1;
  for (usi i : c) {
    vector<ui> g(f);
    for (usi j = 1; j <= i; ++j) {
      for (usi h = 1; j <= j; ++h) f[h + j] = (f[h] * C())
    }
  }
  cout << accumulate(f.begin(), f.end(), uli(0)) % P;
  return 0;
}