#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> T sqr(T x) { return x * x; }
struct point {
  float x, y;
  static float dist(point a, point b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
  }
  friend istream& operator>>(istream& in, point& p) { return in >> p.x >> p.y; }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<point> p(n);
  for (point& i : p) cin >> i;
  vector<vector<float>> dst(n, vector<float>(n));
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < n; ++j) dst[i][j] = point::dist(p[i], p[j]);
  vector<vector<float>> dp(1 << n,
                           vector<float>(n, numeric_limits<float>::infinity()));
  for (size_t i = 0; i < n; ++i) dp[1 << i][i] = point::dist({0, 0}, p[i]);
  for (size_t i = 0; i < (1 << n); ++i)
    if (__builtin_popcount(i) > 1)
      for (size_t j = 0; j < n; ++j)
        if ((i | (1 << j)) == i)
          for (size_t k = 0; k < n; ++k)
            if (k != j && (i & (1 << k)))
              dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + dst[k][j]);
  float ans = numeric_limits<float>::infinity();
  for (size_t i = 0; i < n; ++i) ans = min(ans, dp[(1 << n) - 1][i]);
  cout << fixed << setprecision(2) << ans;
  return 0;
}