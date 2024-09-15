#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> class PrefixSum {
  vector<T> sum;

 public:
  template <typename InputIterator, typename = _RequireInputIter<InputIterator>>
  PrefixSum(InputIterator begin, size_t n): sum(n + 1) {
    typename vector<T>::iterator it = next(sum.begin());
    *(it++) = *begin;
    for (size_t i = 1; i < n; ++i, ++it) *it = *prev(it) + *++begin;
  }
  T get_sum(size_t m, size_t n) { return sum[n] - sum[m]; }
  T get_val(size_t m) { return get_sum(m, m + 1); }
  T operator[](size_t m) { return get_val(m); }
  size_t size(void) { return sum.size(); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  PrefixSum<ui> s(istream_iterator<ui>(cin), n);
  vector<vector<ui>> f(n, vector<ui>(n + 1, numeric_limits<ui>::max()));
  for (size_t i = 0; i < n; ++i) f[i][i] = 0, f[i][i + 1] = s[i];
  for (size_t len = 2; len <= n; ++len)
    for (size_t i = 0, j = len; j <= n; ++i, ++j)
      for (size_t k = i + 1; k < j; ++k)
        f[i][j] = min(f[i][j], f[i][k] + f[k][j] + s.get_sum(i, j));
  cout << f[0][n] - s.get_sum(0, n);
  return 0;
}