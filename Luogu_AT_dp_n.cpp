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
  PrefixSum<uli> s(
      [n]() {
        vector<ui> a(n);
        for (ui &i : a) cin >> i;
        return a;
      }()
          .begin(),
      n);
  vector<vector<uli>> f(n);
  for (size_t i = 0; i < n; ++i) {
    f[i].resize(n - i + 1);
    fill(f[i].begin() + 2, f[i].end(), numeric_limits<uli>::max() / 2);
  }
  for (size_t len = 2; len <= n; ++len)
    for (size_t i = 0; f[i].size() > len; ++i)
      for (size_t k = 1; k < len; ++k)
        f[i][len] =
            min(f[i][len], f[i][k] + f[i + k][len - k] + s.get_sum(i, i + len));
  cout << f[0][n];
  return 0;
}