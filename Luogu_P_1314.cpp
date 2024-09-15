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
  size_t n, m;
  uli s;
  cin >> n >> m >> s;
  vector<pair<ui, ui>> a(n);
  for (pair<ui, ui>& i : a) cin >> i.first >> i.second;
  vector<pair<size_t, size_t>> q(m);
  for (pair<size_t, size_t>& i : q) cin >> i.first >> i.second, --i.first;
  auto f = [&](ui w) {
    vector<bool> u(n);
    vector<ui> v(n);
    for (size_t i = 0; i < n; ++i)
      if (a[i].first >= w) u[i] = true, v[i] = a[i].second;
    PrefixSum<ui> us(u.begin(), n);
    PrefixSum<uli> vs(v.begin(), n);
    uli res = 0;
    for (pair<size_t, size_t> const& i : q)
      res += us.get_sum(i.first, i.second) * vs.get_sum(i.first, i.second);
    return res;
  };
  ui l = 0, r = 1e6 + 1;
  while (l < r) {
    ui mid = (l + r) / 2;
    uli res = f(mid);
    res <= s ? r = mid : l = mid + 1;
  }
  cout << min(abs(li(f(l - 1)) - li(s)), abs(li(f(l)) - li(s)));
  return 0;
}