#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
#define NO          \
  {                 \
    cout << "No\n"; \
    goto nexturn;   \
  }
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<li> b(n), t(n);
    for (li& i : t) cin >> i;
    for (li& i : b) cin >> i;
    vector<pair<li, li>> pr(n >> 1);
    pair<li, li> useful(-1, -1);  // first存x，second存y
    if (n == 1) {
      cout << (b[0] % t[0] ? "No\n" : "Yes\n");
      goto nexturn;
    }                                                         // n=1时特判
    for (size_t i = 0, j = n - 1; i < pr.size(); ++i, --j) {  // j=n-i-1
      if (t[i] == t[j])    // t[i]=t[j]，分式无意义
        pr[i] = {-1, -1};  // 特殊标记
      else {
        if ((b[i] - b[j]) % (t[i] - t[j]))
          NO  // 不能整除
              pr[i]
                  .first = (b[i] - b[j]) / (t[i] - t[j]);  // x
        if ((b[i] - pr[i].first * t[i]) % (t[i] + t[j]))
          NO  // 同理，求y时判断是否整除
              pr[i]
                  .second = (b[i] - pr[i].first * t[i]) / (t[i] + t[j]);  // y
        if (pr[i].first < 0 || pr[i].second < 0) NO;  // 解<0，不合理
      }
    }
    for (pair<li, li> const& i : pr)
      if (i != useful) {  // 寻找一组有意义的解
        useful = i;
        break;
      }
    if (useful == pair<li, li>(-1, -1)) {  // 没找到
      li times = b[0] / t[0];
      for (size_t i = 0; i < n; ++i)
        if (b[i] % t[i] || b[i] / t[i] != times) NO  // 判断是否整除、商均像等
    } else
      for (size_t i = 0, j = n - 1; i < (n + 1 >> 1); ++i, --j)
        if (b[i] != useful.first * t[i] + useful.second * (t[i] + t[j]) ||
            b[j] != useful.first * t[j] + useful.second * (t[i] + t[j]))
          NO  // 带回验证
                  cout
              << "Yes\n";
  nexturn:;
  }
  return 0;
}