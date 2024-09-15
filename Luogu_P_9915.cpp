#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 998244353;
constexpr ui fast_pow(ui a, uli n) {
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
  uli n;
  size_t q;
  fin >> n >> q;
  while (q--) {
    uli x, y;
    fin >> x >> y;
    if (y >= 64 || !(x >>= y))
      fout << fast_pow(2, n) - 1 << '\n';
    else {
      bool flag = x % 2;
      do x >>= 1, ++y;
      while (x % 2 == flag);
      fout << fast_pow(2, y) - 1 << '\n';
    }
  }
  return 0;
}