#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> struct Difference {
  vector<T> d;
  template <typename InputIterator>
  Difference(InputIterator begin, size_t n): d(n) {
    InputIterator lst(begin++);
    typename vector<T>::iterator it = d.begin();
    *(it++) = *lst;
    while (true) {
      *it = *begin - *lst;
      if (++it >= d.end()) break;
      lst = begin++;
    }
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
  size_t n, m;
  cin >> n >> m;
  Difference<li> d(n);
  vector<uli> g(m);
  for (uli& i : g) cin >> i, --i;
  uli bv = 0;
  for (vector<uli>::const_iterator it = g.cbegin(), jt = next(it);
       jt < g.cend(); ++it, ++jt) {
    uli x = min(*it, *jt), y = max(*it, *jt);
    if (y - x <= n / 2)
      d.add_interval(x, y, n - (y - x) - (y - x)), bv += y - x;
    else
      d.add_interval(y, n, n - (n - (y - x)) - (n - (y - x))),
          d.add_interval(0, x, n - (n - (y - x)) - (n - (y - x))),
          bv += n - (y - x);
  }
  vector<uli> yd(n);
  d.get_arr(yd.begin());
  uli minyd = numeric_limits<uli>::max();
  for (uli i : yd) minyd = min(minyd, i);
  cout << (bv += minyd);
  return 0;
}