#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<double> f(n);
  f[0] = 1;
  double sum = 0;
  const size_t T = 1e7 / n;
  for (size_t i = 1; i <= T; ++i) {
    sum += f.back() * (uli(i + 1) * i / 2);
    vector<double> g(n);
    for (ui j = 1; j < n; ++j)
      g[j - 1] += f[j - 1] * j / n, g[j] += f[j - 1] * (n - j) / n;
    f = g;
  }
  cout << fixed << setprecision(2) << sum;
  return 0;
}