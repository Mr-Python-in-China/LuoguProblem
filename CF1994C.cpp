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
    ui x;
    cin >> n >> x;
    PrefixSum<uli> s(
        [n] {
          vector<ui> a(n);
          for (ui &i : a) cin >> i;
          return a;
        }()
            .begin(),
        n);
    vector<size_t> jmp(n);
    for (size_t i = 0; i < n; ++i) {
      size_t l = i, r = n;
      while (l < r) {
        size_t mid = (l + r + 1) / 2;
        s.get_sum(i, mid) > x ? r = mid - 1 : l = mid;
      }
      jmp[i] = l;
    }
    vector<size_t> ans(n + 2);
    for (size_t i = n - 1; i < n; --i) ans[i] = ans[jmp[i] + 1] + (jmp[i] - i);
    cout << accumulate(ans.begin(), next(ans.begin(), n), uli(0)) << '\n';
  }
  return 0;
}