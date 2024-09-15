#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using uc = unsigned char;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<char> c(n);
    for (char &i : c) cin >> i;
    if (n == 2) {
      cout << ((c[0] - '0') * 10 + (c[1] - '0')) << '\n';
      continue;
    }
    ui ans = numeric_limits<ui>::max();
    for (size_t i = 0; i < n - 1; ++i) {
      vector<uc> p;
      for (size_t j = 0; j < n; ++j)
        if (j == i) {
          p.emplace_back((c[j] - '0') * 10 + (c[j + 1] - '0'));
          ++j;
        } else
          p.emplace_back(c[j] - '0');
      if (count(p.begin(), p.end(), 0)) {
        cout << "0\n";
        goto end;
      } else
        ans = min(ans, max<ui>(accumulate(p.begin(), p.end(), ui(0)) -
                                   count(p.begin(), p.end(), 1),
                               1));
    }
    cout << ans << '\n';
  end:;
  }
  return 0;
}