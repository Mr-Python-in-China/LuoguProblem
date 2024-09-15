#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  array<uli, 4> c;
  size_t n;
  cin >> c[0] >> c[1] >> c[2] >> c[3] >> n;
  while (n--) {
    array<uli, 4> d;
    ui t;
    cin >> d[0] >> d[1] >> d[2] >> d[3] >> t;
    vector<uli> f(t + 1);
    f[0] = 1;
    for (size_t o = 0; o < 4; ++o) {
      ui w = c[o], m = d[o];
      vector<uli> g(f);
      vector<uli> s(w);
      for (uli i = 0; i * w <= t; ++i)
        for (uli j = 0; j < w && i * w + j <= t; ++j) {
          g[i * w + j] += s[j];
          s[j] += f[i * w + j];
          if (i >= m) s[j] -= f[(i - m) * w + j];
        }
      f = g;
    }
    cout << f.back() << '\n';
  }
  return 0;
}