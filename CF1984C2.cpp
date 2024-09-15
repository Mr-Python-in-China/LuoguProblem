#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 998244353;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    li minc, maxc;
    ui minc_cnt, maxc_cnt;
    {
      int x;
      cin >> x;
      minc = x, maxc = abs(x);
      if (minc == maxc)
        minc_cnt = 0, maxc_cnt = 2;
      else
        minc_cnt = maxc_cnt = 1;
    }
    for (size_t i = 1; i < n; ++i) {
      int x;
      cin >> x;
      li nminc = min({minc + x, abs(minc + x), maxc + x, abs(maxc + x)}),
         nmaxc = max({minc + x, abs(minc + x), maxc + x, abs(maxc + x)});
      li nminc_cnt = 0, nmaxc_cnt = 0;
      if (minc + x == nminc) (nminc_cnt += minc_cnt) %= P;
      if (abs(minc + x) == nminc) (nminc_cnt += minc_cnt) %= P;
      if (maxc + x == nminc) (nminc_cnt += maxc_cnt) %= P;
      if (abs(maxc + x) == nminc) (nminc_cnt += maxc_cnt) %= P;
      if (minc + x == nmaxc) (nmaxc_cnt += minc_cnt) %= P;
      if (abs(minc + x) == nmaxc) (nmaxc_cnt += minc_cnt) %= P;
      if (maxc + x == nmaxc) (nmaxc_cnt += maxc_cnt) %= P;
      if (abs(maxc + x) == nmaxc) (nmaxc_cnt += maxc_cnt) %= P;
      minc_cnt = nminc_cnt, maxc_cnt = nmaxc_cnt, minc = nminc, maxc = nmaxc;
      if (minc == maxc) minc_cnt = 0;
    }
    cout << maxc_cnt << '\n';
  }
  return 0;
}