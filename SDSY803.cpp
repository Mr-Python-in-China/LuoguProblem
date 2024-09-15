#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T, typename cmp = less<T>> struct STtable {
  vector<T> arr;
  vector<vector<size_t>> table;
  static size_t lg2(size_t x) { return log2(max<size_t>(--x, 1)) + 1; }
  size_t getcmp(size_t x, size_t y) { return cmp()(arr[x], arr[y]) ? x : y; }
  template <typename InputIterator, typename = _RequireInputIter<InputIterator>>
  STtable(InputIterator it, size_t n): arr(n), table(lg2(n)) {
    std::copy_n(it, n, arr.begin());
    table.front().resize(n);
    iota(table.front().begin(), table.front().end(), size_t());
    for (size_t i = 1; i < table.size(); i++) {
      size_t k = 1 << i;
      table[i].resize(n - k + 1);
      for (size_t r = k; r <= n; r++)
        table[i][r - k] =
            getcmp(table[i - 1][r - k], table[i - 1][r - (k >> 1)]);
    }
  }
  T const& operator[](size_t p) { return arr[p]; }
  size_t getpos(size_t l, size_t r) {
    size_t k = lg2(r - l) - 1;
    return getcmp(table[k][l], table[k][r - (1 << k)]);
  }
  size_t getval(size_t l, size_t r) { return arr[getpos(l, r)]; }
};
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
  if (!(cin >> n && n)) return 0;
  cin >> m;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  a.push_back(numeric_limits<int>::max());
  map<int, size_t> mp;
  STtable<size_t, greater<size_t>> st(([&]() {
                                        vector<size_t> s;
                                        int lst = ~0;
                                        for (int i : a)
                                          if (i == lst)
                                            ++s.back();
                                          else
                                            mp.emplace(i, s.size()),
                                                s.emplace_back(1), lst = i;
                                        return s;
                                      })()
                                          .begin(),
                                      n);
  PrefixSum<size_t> u(st.arr.begin(), n);
  while (m--) {
    size_t l, r;
    cin >> l >> r;
    --l;
    size_t s = mp.upper_bound(a[l])->second, t = mp.lower_bound(a[r])->second;
    cout << max({s == t ? 0 : st.getval(s, t), u.get_sum(0, s) - l,
                 r - u.get_sum(0, t)})
         << '\n';
  }
  return main();
}
