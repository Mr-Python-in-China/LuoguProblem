#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<bool> s(n);
  for (vector<bool>::reference i : s) {
    char c;
    cin >> c;
    i = c == '1';
  }
  vector<ui> c(n);
  for (ui& i : c) cin >> i;
  uli ans = numeric_limits<uli>::max();
  size_t p[2][2] = {}, b[2][2] = {};
  for (size_t i = 1; i < n; ++i) b[i & 1][!s[i]] += c[i];
  for (size_t i = 0, j = 1; j < n; ++i, ++j) {
    b[j & 1][!s[j]] -= c[j];
    ans = min<uli>({ans,
                    p[j & 1][1] + p[i & 1][0] + b[i & 1][1] + b[j & 1][0] +
                        (s[i] != 0) * c[i] + (s[j] != 0) * c[j],
                    p[j & 1][0] + p[i & 1][1] + b[i & 1][0] + b[j & 1][1] +
                        (s[i] != 1) * c[i] + (s[j] != 1) * c[j]});
    p[i & 1][!s[i]] += c[i];
  }
  cout << ans;
  return 0;
}