#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T, typename cmp = less<T>, typename Alloc = allocator<T>>
class STtable {
  Alloc T* arr;
  T** table;
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
template <typename T> struct demopnse {
  struct block {
    size_t invl, invr;
    STtable<T, greater<T>> table;
    block(block&) = delete;
    template <typename RandomIterator> block(RandomIterator it, )
  }
};
namespace GenHelper {
unsigned z1, z2, z3, z4, b;
unsigned rand_() {
  b = ((z1 << 6) ^ z1) >> 13;
  z1 = ((z1 & 4294967294U) << 18) ^ b;
  b = ((z2 << 2) ^ z2) >> 27;
  z2 = ((z2 & 4294967288U) << 2) ^ b;
  b = ((z3 << 13) ^ z3) >> 21;
  z3 = ((z3 & 4294967280U) << 7) ^ b;
  b = ((z4 << 3) ^ z4) >> 12;
  z4 = ((z4 & 4294967168U) << 13) ^ b;
  return (z1 ^ z2 ^ z3 ^ z4);
}
void srand(unsigned x) {
  z1 = x;
  z2 = (~x) ^ 0x233333333U;
  z3 = x ^ 0x1234598766U;
  z4 = (~x) + 51;
}
int read() {
  int a = rand_() & 32767;
  int b = rand_() & 32767;
  return a * 32768 + b;
}
}  // namespace GenHelper
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, s;
  cin >> n >> m >> s;
  GenHelper::srand(s);
  vector<int> a(n);
  for (int& i : a) i = GenHelper::read();
  STtable<int, greater<int>> st(a.cbegin(), n);
  uli ans = 0;
  while (m--) {
    size_t l = GenHelper::read() % n + 1, r = GenHelper::read() % n + 1;
    if (l > r) swap(l, r);
    --l;
    ans += st.getval(l, r);
  }
  cout << ans;
  return 0;
}