#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename ForwardIterator,
          typename = is_unsigned<typename ForwardIterator::value_type>>
void radixSort(ForwardIterator first, ForwardIterator last) {
  constexpr ui P = 65536;
  constexpr size_t T = 2;
  size_t n = distance(first, last);
  ui W = 1;
  for (size_t i = 0; i < T; ++i, W *= P) {
    array<size_t, P> cnt{};
    for_each(first, last, [&](typename ForwardIterator::reference const x) {
      ++cnt[x / W % P];
    });
    partial_sum(cnt.begin(), cnt.end(), cnt.begin());
    rotate(cnt.begin(), prev(cnt.end()), cnt.end()), cnt[0] = 0;
    vector<typename ForwardIterator::value_type> dat(n);
    for_each(first, last, [&](typename ForwardIterator::reference const x) {
      dat[cnt[x / W % P]++] = x;
    });
    copy(dat.begin(), dat.end(), first);
  }
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<ui> a(n);
  for (ui &i : a) cin >> i;
  radixSort(a.begin(), a.end());
  for (ui i : a) cout << i << ' ';
  return 0;
}