#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> struct Difference {
  vector<T> d;
  template <typename InputIterator, typename = _RequireInputIter<InputIterator>>
  Difference(InputIterator begin, size_t n): d(n) {
    InputIterator lst(begin++);
    typename vector<T>::iterator it = d.begin();
    *(it++) = *begin;
    for (size_t i = 1; i < n; ++i, ++it) *it = *begin - *lst, lst = begin++;
  }
  Difference(size_t n): d(n) {}
  void add_interval(size_t l, size_t r, T val) {
    d[l] += val;
    if (r < d.size()) d[r] -= val;
  }
  template <typename OutputIterator> void get_arr(OutputIterator output) {
    T sum = 0;
    typename vector<T>::iterator it = d.begin();
    while (true) {
      *output = (sum += *it);
      if (++it >= d.end()) break;
      ++output;
    }
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, k;
  cin >> n >> k;
  Difference<int> d(n);
  while (k--) {
    size_t l, r;
    cin >> l >> r;
    d.add_interval(--l, r, 1);
  }
  vector<int> a(n);
  d.get_arr(a.begin());
  nth_element(a.begin(), a.begin() + n / 2, a.end());
  cout << a[n / 2];
  return 0;
}