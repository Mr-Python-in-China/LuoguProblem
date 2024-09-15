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
uli f(size_t n, size_t k, vector<vector<uli>> const& a) {
  vector<vector<uli>> ul(n, vector<uli>(n)), ur(n, vector<uli>(n));
  ul[0][0] = a[0][0];
  for (size_t i = 1; i < n; ++i) ul[i][0] = max(ul[i - 1][0], a[i][0]);
  for (size_t j = 1; j < n; ++j) ul[0][j] = max(ul[0][j - 1], a[0][j]);
  for (size_t i = 1; i < n; ++i)
    for (size_t j = 1; j < n; ++j)
      ul[i][j] = max({ul[i - 1][j], ul[i][j - 1], a[i][j]});
  ur[0][n - 1] = a[0][n - 1];
  for (size_t i = 1; i < n; ++i)
    ur[i][n - 1] = max(ur[i - 1][n - 1], a[i][n - 1]);
  for (size_t j = n - 2; j < n; --j) ur[0][j] = max(ur[0][j + 1], a[0][j]);
  for (size_t i = 1; i < n; ++i)
    for (size_t j = n - 2; j < n; --j)
      ur[i][j] = max({ur[i - 1][j], ur[i][j + 1], a[i][j]});
  vector<uli> d(n);
  d[n - 1] = *max_element(a[n - 1].cbegin(), a[n - 1].cend());
  for (size_t i = n - 2; i < n; --i)
    d[i] = max(d[i + 1], *max_element(a[i].cbegin(), a[i].cend()));
  uli ans = numeric_limits<uli>::min();
  for (size_t i = 0; i + k < n; ++i)
    for (size_t j = 0; j + k < n; ++j)
      ans = max(ans, ul[i][j] + ur[i][j + k] + d[i + k]);
  return ans;
}
uli g(size_t n, size_t k, vector<vector<uli>> const& a) {
  vector<uli> mx(n);
  for (size_t i = 0; i < n; ++i) mx[i] = *max_element(a[i].begin(), a[i].end());
  vector<vector<uli>> d(n);
  for (size_t i = 0; i < n; ++i) {
    d[i].push_back(mx[i]);
    for (size_t j = i + 1; j < n; ++j) d[i].push_back(max(mx[j], d[i].back()));
  }
  uli ans = numeric_limits<uli>::min();
  for (size_t i = 0; i + k < n; ++i)
    for (size_t j = i + k; j + k < n; ++j)
      ans = max(
          ans, d[0][i - 0] + d[i + k][j - (i + k)] + d[j + k][n - 1 - (j + k)]);
  return ans;
}
vector<vector<uli>> rotate(size_t n, vector<vector<uli>> const& x) {
  vector<vector<uli>> y(n, vector<uli>(n));
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < n; ++j) y[i][j] = x[j][n - i - 1];
  return y;
}
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
  cout << max({f(k, m, b), g(k, m, b), f(k, m, rotate(k, b)),
               g(k, m, rotate(k, b)), f(k, m, rotate(k, rotate(k, b))),
               g(k, m, rotate(k, rotate(k, b))),
               f(k, m, rotate(k, rotate(k, rotate(k, b)))),
               g(k, m, rotate(k, rotate(k, rotate(k, b))))});
  return 0;
}