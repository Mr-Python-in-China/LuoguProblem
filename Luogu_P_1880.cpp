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
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  a.insert(a.end(), a.begin(), prev(a.end()));
  PrefixSum<ui> s(a.begin(), a.size());
  vector<vector<ui>> fn(a.size(),
                        vector<ui>(a.size() + 1, numeric_limits<ui>::max())),
      fx(a.size(), vector<ui>(a.size() + 1, numeric_limits<ui>::min()));
  for (size_t i = 0; i < a.size(); ++i) fn[i][i + 1] = fx[i][i + 1] = 0;
  for (size_t len = 2; len <= a.size(); ++len)
    for (size_t i = 0, j = len; j <= a.size(); ++i, ++j)
      for (size_t k = i + 1; k < j; ++k)
        fn[i][j] = min(fn[i][j], fn[i][k] + fn[k][j] + s.get_sum(i, j)),
        fx[i][j] = max(fx[i][j], fx[i][k] + fx[k][j] + s.get_sum(i, j));
  ui ansn = numeric_limits<ui>::max(), ansx = numeric_limits<ui>::min();
  for (size_t i = 0, j = n; j <= a.size(); ++i, ++j)
    ansn = min(ansn, fn[i][j]), ansx = max(ansx, fx[i][j]);
  cout << ansn << '\n' << ansx;
  return 0;
}