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
    size_t n;
    cin >> n;
    vector<unsigned short int> a(n);
    for (unsigned short int& i : a) cin >> i;
    PrefixSum<ui> s(a.cbegin(), n);
    size_t q;
    cin >> q;
    while (q--) {
      size_t d;
      ui u;
      cin >> d >> u;
      --d;
      size_t l = d + 1, r = n;
      while (l < r) {
        size_t mid = (l + r) / 2;
        s.get_sum(d, mid) > u ? r = mid : l = mid + 1;
      }
      auto f = [&](size_t p) {
        li sum = s.get_sum(d, p);
        return li(u) * sum - sum * (sum - 1) / 2;
      };
      cout << (l - 1 > d && f(l - 1) >= f(l) ? l - 1 : l) << ' ';
    }
    cout << '\n';
  }
  return 0;
}