#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, q;
  float a;
  cin >> n >> a >> q;
  a /= 100;
  vector<bool> b(n);
  for (vector<bool>::reference i : b) {
    char c;
    cin >> c;
    i = c == '1';
  }
  vector<float> f(n + 1);
  f[0] = 1;
  for (size_t i = 0; i < n; ++i) {
    vector<float> g(n + 1);
    float const x = b[i] ? a : 1 - a, y = 1 - x;
    g[0] = f[0] * y;
    for (size_t j = 1; j <= n; ++j) g[j] = f[j] * y + f[j - 1] * x;
    f = g;
  }
  cout << fixed << setprecision(3) << accumulate(f.begin() + q, f.end(), 0.0);
  return 0;
}