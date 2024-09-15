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
    cin >> n;
    vector<ui> a(n);
    for (ui& i : a) cin >> i;
    vector<size_t> zz(n);
    zz.front() = 1, zz.back() = n - 2;
    for (size_t i = 1; i < zz.size() - 1; ++i)
      zz[i] = a[i] - a[i - 1] < a[i + 1] - a[i] ? i - 1 : i + 1;
    vector<ui> forward(n - 1), backward(n - 1);
    for (size_t i = 0; i < n - 1; ++i)
      forward[i] = zz[i] == i + 1 ? 1 : a[i + 1] - a[i];
    for (size_t i = n - 1; i > 0; --i)
      backward[n - i - 1] = zz[i] == i - 1 ? 1 : a[i] - a[i - 1];
    PrefixSum<uli> forward_sum(forward.begin(), n - 1),
        backward_sum(backward.begin(), n - 1);
    size_t q;
    cin >> q;
    while (q--) {
      size_t x, y;
      cin >> x >> y;
      --x, --y;
      if (x < y)
        cout << forward_sum.get_sum(x, y);
      else
        cout << backward_sum.get_sum(n - x - 1, n - y - 1);
      cout.put('\n');
    }
  }
  return 0;
}