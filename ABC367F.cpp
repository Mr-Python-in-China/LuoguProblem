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
  size_t n, q;
  fin >> n >> q;
  vector<uint_fast32_t> mapper(n);
  random_device rd;
  for (uint_fast32_t &i : mapper) i = rd();
  vector<uint_fast32_t> a(n), b(n);
  for (uint_fast32_t &i : a) fin >> i, i = mapper[i - 1];
  for (uint_fast32_t &i : b) fin >> i, i = mapper[i - 1];
  PrefixSum<uli> s(a.begin(), n), t(b.begin(), n);
  while (q--) {
    size_t i, j, k, l;
    fin >> i >> j >> k >> l;
    if (j - --i != l - --k) {
      fout << "No\n";
      continue;
    }
    fout << (s.get_sum(i, j) == t.get_sum(k, l) ? "Yes\n" : "No\n");
  }
  return 0;
}