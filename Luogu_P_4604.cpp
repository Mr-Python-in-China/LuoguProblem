#include <bits/extc++.h>
using namespace std;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
ui next_integer(ui x) {
  x ^= x << 13;
  x ^= x >> 17;
  x ^= x << 5;
  return x;
}
void output_arr(void *a, ui size) {
  assert(size % 4 == 0);
  ui blocks = size / 4;
  ui *A = (ui *)a;
  ui ret = size;
  ui x = 23333333;
  for (ui i = 0; i < blocks; i++) {
    ret = ret ^ (A[i] + x);
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
  }
  fout << ret;
}
namespace TaskA {
template <typename ForwardIterator,
          typename = is_unsigned<typename ForwardIterator::value_type>>
void radixSort(ForwardIterator first, ForwardIterator last) {
  constexpr ui P = 8;
  constexpr size_t T = 4;
  size_t n = distance(first, last);
  ui W = 0;
  auto *dat = new typename ForwardIterator::value_type[n];
  for (size_t i = 0; i < T; ++i, W += P) {
    array<size_t, 1u << P> cnt{};
    for_each(first, last, [&](typename ForwardIterator::reference const x) {
      ++cnt[(x >> W) & ((1u << P) - 1)];
    });
    partial_sum(cnt.begin(), cnt.end(), cnt.begin());
    rotate(cnt.begin(), prev(cnt.end()), cnt.end()), cnt[0] = 0;
    for_each(first, last, [&](typename ForwardIterator::reference const x) {
      dat[cnt[(x >> W) & ((1u << P) - 1)]++] = x;
    });
    copy(dat, dat + n, first);
  }
  delete[] dat;
}
void main(void) {
  size_t n;
  ui s;
  fin >> n >> s;
  vector<ui> a(n);
  for (ui &i : a) s = i = next_integer(s);
  radixSort(a.begin(), a.end());
  output_arr(a.data(), a.size() * 4);
}
}  // namespace TaskA
namespace TaskB {
template <typename InputIterator,
          typename = is_same<
              typename iterator_traits<InputIterator>::value_type, bool>>
uli iterator_to_ull(InputIterator first, InputIterator last) {
  uli res = 0;
  for (; first != last; ++first) (res <<= 1) |= *first;
  return res;
}
void main(void) {
  size_t n, q;
  fin >> n >> q;
  vector<bool> a(n * 3), b(n * 3);
  vector<ui> ansarr(q);
  for (size_t j = 0; j < n; ++j) {
    char c;
    fin >> c;
    a[j * 3 + (c - '0')] = true;
  }
  for (size_t j = 0; j < n; ++j) {
    char c;
    fin >> c;
    b[j * 3 + (c - '0' + 2) % 3] = true;
  }
  array<vector<uli>, 64> f, g;
  for (size_t i = 0; i + 64 <= a.size(); ++i)
    f[i % 64].emplace_back(iterator_to_ull(a.begin() + i, a.begin() + i + 64));
  for (size_t i = 0; i + 64 <= b.size(); ++i)
    g[i % 64].emplace_back(iterator_to_ull(b.begin() + i, b.begin() + i + 64));
  for (ui &ans : ansarr) {
    size_t x, y, l;
    cin >> x >> y >> l;
    x *= 3, y *= 3, l *= 3;
    size_t i = 0;
    for (vector<uli>::iterator it = f[x % 64].begin() + x / 64,
                               jt = g[y % 64].begin() + y / 64;
         i + 64 <= l; i += 64, ++it, ++jt)
      ans += __builtin_popcountll(*it & *jt);
    for (; i < l; ++i) ans += a[x + i] && b[y + i];
  }
  output_arr(ansarr.data(), ansarr.size() * 4);
}
}  // namespace TaskB
namespace TaskC {
void main(void) {
  size_t n;
  cin >> n;
  ui *dat = new ui[n + 1];
  ui *first = dat + n;
  *first = 1;
  size_t sz = 1;
  for (size_t T = 0; T < n; ++T) {
    char c;
    cin >> c;
    if (c == '(') {
      *--first = 0;
      sz = min(sz + 1, n - T + 2);
    } else if (c == ')') {
      ++first;
      if ((sz = min(sz - 1, n - T + 2)) == 0) {
        cout << "0";
        return;
      }
    } else {
      --first;
      sz = min(sz + 1, n - T + 2);
      *first = 0;
      for (size_t i = (T & 1) ^ 1; i + 2 < sz; i += 2) first[i] += first[i + 2];
    }
  }
  cout << *first;
  delete[] dat;
}
}  // namespace TaskC
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  char c;
  fin >> c;
  (c == '1'   ? TaskA::main
   : c == '2' ? TaskB::main
   : c == '3' ? TaskC::main
              : throw)();
  return 0;
}