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
    while (true) {
      *it = *prev(it) + *begin;
      if (++it >= sum.end()) break;
      ++begin;
    }
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
    uli k;
    cin >> n >> k;
    vector<uli> a(n);
    for (uli& i : a) cin >> i;
    uli lsth;
    size_t ql = 0, ans = 0;
    cin >> lsth;
    for (size_t i = 1; i < n; ++i) {
      uli nowh;
      cin >> nowh;
      if (lsth % nowh) {
        size_t itl = ql, itr = ql;
        uli sum = 0;
        for (; itr < i; ++itr) {
          sum += a[itr];
          while (sum > k) sum -= a[itl++];
          ans = max(ans, itr - itl + 1);
        }
        ql = i;
      }
      lsth = nowh;
    }
    {
      size_t itl = ql, itr = ql;
      uli sum = 0;
      for (; itr < n; ++itr) {
        sum += a[itr];
        while (sum > k) sum -= a[itl++];
        ans = max(ans, itr - itl + 1);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}