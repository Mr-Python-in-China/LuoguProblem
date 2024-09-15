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
    InputIterator last(begin++);
    typename vector<T>::iterator it = d.begin();
    *(it++) = *begin;
    for (size_t i = 1; i < n; ++i, ++it) *it = *begin - *last, last = begin++;
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
  size_t n;
  ui k;
  cin >> n >> k;
  vector<pair<ui, bool>> op(n);
  for (pair<ui, bool>& i : op) {
    char c;
    cin >> i.first >> c;
    i.second = c == 'R';
  }
  unordered_map<li, size_t> mr;
  vector<li> ms;
  {
    li p = 0;
    set<li> s({p});
    for (pair<ui, bool> i : op)
      s.insert(i.second ? p += i.first : p -= i.first);
    ms.resize(s.size());
    size_t i = 0;
    for (set<li>::const_iterator it = s.cbegin(); it != s.cend(); ++it, ++i)
      mr[*it] = i, ms[i] = *it;
  }
  li p = 0;
  Difference<int> d(ms.size());
  for (pair<ui, bool> i : op) {
    li q = i.second ? p + i.first : p - i.first;
    d.add_interval(mr[min(p, q)], mr[max(p, q)], 1);
    p = q;
  }
  uli ans = 0;
  vector<int> yy(ms.size());
  d.get_arr(yy.begin());
  for (size_t i = 0; i < ms.size() - 1; ++i)
    if (yy[i] >= k) ans += ms[i + 1] - ms[i];
  cout << ans;
  return 0;
}