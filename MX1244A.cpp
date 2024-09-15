#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
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
  fin >> n;
  PrefixSum<ui> s(
      [n] {
        vector<ui> c(n);
        for (ui &i : c) fin >> i;
        return c;
      }()
          .begin(),
      n);
  vector<vector<ui>> f(n + 1);
  for (size_t i = 0; i <= n; ++i) f[i].resize(min((i + 1) * 2, n - i) + 1);
  vector<vector<ui>> g = f;
  for (size_t i = n - 1; i < n; --i) {
    f[i][0] = 0, g[i][0] = numeric_limits<ui>::max() / 2;
    for (size_t k = 1; k < f[i].size(); ++k) {
      f[i][k] = max(f[i][k - 1], g[i + k][min(k * 2, g[i + k].size() - 1)] +
                                     s.get_sum(i, i + k));
      g[i][k] = min(g[i][k - 1], f[i + k][min(k * 2, f[i + k].size() - 1)]);
    }
  }
  fout << max(f[0][1], f[0][2]);
  return 0;
}