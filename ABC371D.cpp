#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
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
  fin >> n;
  vector<int> x(n);
  vector<ui> p(n);
  for (int& i : x) fin >> i;
  for (ui& i : p) fin >> i;
  PrefixSum<uli> s(p.begin(), n);
  fin >> q;
  while (q--) {
    int l, r;
    fin >> l >> r;
    size_t a = lower_bound(x.begin(), x.end(), l) - x.begin(),
           b = upper_bound(x.begin(), x.end(), r) - x.begin();
    fout << s.get_sum(a, b) << '\n';
  }
  return 0;
}