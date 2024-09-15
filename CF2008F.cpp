#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 1e9 + 7;
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
  size_t T;
  fin >> T;
  while (T--) {
    size_t n;
    fin >> n;
    ui presum = 0, ans = 0;
    for (size_t i = 0; i < n; ++i) {
      ui x;
      fin >> x;
      ans = (ans + (uli)x * presum) % P;
      presum = (presum + (uli)x) % P;
    }
    fout << ans * (uli)fast_pow(n * uli(n - 1) / 2 % P, P - 2) % P << '\n';
  }
  return 0;
}