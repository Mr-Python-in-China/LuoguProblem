#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> class PrefixSum2D {
  vector<vector<T>> sum;

 public:
  template <typename S>
  PrefixSum2D(vector<vector<S>> const& a)
      : sum(a.size() + 1, vector<T>(a.front().size() + 1)) {
    size_t const n = a.size(), m = a.front().size();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++)
        sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + a[i][j];
  }
  T get_sum(size_t ax, size_t ay, size_t bx, size_t by) const {
    return sum[bx][by] + sum[ax][ay] - sum[ax][by] - sum[bx][ay];
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<vector<ui>> a(n, vector<ui>(n));
  for (vector<ui>& i : a)
    for (ui& j : i) cin >> j;
  size_t k = n - m + 1;
  vector<vector<uli>> b(k, vector<uli>(k));
  {
    PrefixSum2D<uli> s(a);
    for (size_t i = 0; i < k; ++i)
      for (size_t j = 0; j < k; ++j) b[i][j] = s.get_sum(i, j, i + m, j + m);
  }
  vector<vector<uli>> m0(k + 1, vector<uli>(k + 1));
  for (size_t i = 0; i < k; ++i)
    for (size_t j = 0; j < k; ++j)
      m0[i + 1][j + 1] = max({m0[i + 1][j], m0[i][j + 1], b[i][j]});
  vector<vector<uli>> c(k, vector<uli>(k));
  for (size_t i = 0; i < k; ++i)
    for (size_t j = 0; j < k; ++j)
      c[i][j] = max(i + 1 >= m ? m0[i - m + 1][k] : 0,
                    j + 1 >= m ? m0[k][j - m + 1] : 0) +
                b[i][j];
  vector<vector<uli>> m1(k + 1, vector<uli>(k + 1));
  for (size_t i = 0; i < k; ++i)
    for (size_t j = 0; j < k; ++j)
      m1[i + 1][j + 1] = max({m1[i + 1][j], m1[i][j + 1], c[i][j]});
  vector<vector<uli>> d(k, vector<uli>(k));
  for (size_t i = 0; i < k; ++i)
    for (size_t j = 0; j < k; ++j)
      d[i][j] = max(i + 1 >= m ? m1[i - m + 1][k] : 0,
                    j + 1 >= m ? m1[k][j - m + 1] : 0) +
                b[i][j];
  uli ans = 0;
  for (size_t i = 0; i < k; ++i)
    for (size_t j = 0; j < k; ++j) ans = max(ans, d[i][j]);
  cout << ans;
  return 0;
}