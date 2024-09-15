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
  size_t n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> beva(n, vector<int>(m));
  for (vector<int>& i : beva)
    for (int& j : i) {
      char c;
      cin >> c;
      j = c == '.'   ? 0
          : c == 'o' ? 1
          : c == 'x' ? numeric_limits<int>::min()
                     : throw;
    }
  PrefixSum2D<li> s(beva);
  ui ans = numeric_limits<ui>::max();
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < m; ++j) {
      if (i + k <= n && s.get_sum(i, j, i + k, j + 1) >= 0)
        ans = min<ui>(ans, k - s.get_sum(i, j, i + k, j + 1));
      if (j + k <= m && s.get_sum(i, j, i + 1, j + k) >= 0)
        ans = min<ui>(ans, k - s.get_sum(i, j, i + 1, j + k));
    }
  cout << int(ans);
  return 0;
}