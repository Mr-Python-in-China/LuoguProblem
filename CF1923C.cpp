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
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, q;
    cin >> n >> q;
    vector<ui> a(n);
    vector<bool> is1(n);
    for (size_t i = 0; i < n; ++i) cin >> a[i], is1[i] = a[i] == 1;
    PrefixSum<uli> s(a.cbegin(), n), t(is1.cbegin(), n);
    while (q--) {
      size_t l, r;
      cin >> l >> r;
      --l;
      cout << (r - l == 1 || s.get_sum(l, r) - t.get_sum(l, r) < r - l
                   ? "NO\n"
                   : "YES\n");
    }
  }
  return 0;
}