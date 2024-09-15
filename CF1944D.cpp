#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 2147483647;
constexpr ui fastpow(ui a, ui n) {
  ui ans = 1;
  while (n) {
    if (n & 1) ans = uli(ans) * a % P;
    a = uli(a) * a % P;
    n >>= 1;
  }
  return ans;
}
template <typename T, typename cmp = less<T>> class STtable {
  vector<vector<size_t>> table;
  vector<T> arr;
  static size_t lg2(size_t x) { return log2(max<size_t>(--x, 1)) + 1; }
  size_t getcmp(size_t x, size_t y) { return cmp()(arr[x], arr[y]) ? x : y; }

 public:
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
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  std::random_device rd;
  const uli base = uniform_int_distribution<uli>(128, 256)(rd);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<ui> hs0({0}), hs1({0});
    for_each(s.begin(), s.end(),
             [&hs0, base](char c) { hs0.push_back(hs0.back() * base % P); });
    for_each(s.rbegin(), s.rend(),
             [&hs1, base](char c) { hs1.push_back(hs1.back() * base % P); });
    vector<ui> lg1(n), lg0(n - 1);
    for (size_t i = 0; i < n; ++i) {
      size_t l = 1, r = min(i, n - i - 1);
      while (l < r) {
        size_t mid = (l + r) / 2;
        hs0
      }
    }
  }
  return 0;
}