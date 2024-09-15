#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<ui> a(n);
    for (ui &i : a) cin >> i;
    vector<ui> b;
    for (size_t i = 1; i < a.size(); ++i) b.emplace_back(__gcd(a[i - 1], a[i]));
    set<size_t> errpoint;
    for (size_t i = 1; i < b.size(); ++i)
      if (b[i - 1] > b[i]) errpoint.insert(i - 1);
    if (errpoint.empty() || (errpoint.size() == 1 && errpoint.count(0))) {
      cout << "YES";
      goto successful;
    }
    for (size_t i = 1; i + 1 < n; ++i) {
      size_t v = __gcd(a[i - 1], a[i + 1]);
      if (!((i == 1 ? 0 : b[i - 2]) <= v &&
            v <= (i + 2 == n ? numeric_limits<ui>::max() : b[i + 1])))
        continue;
      if (errpoint.count(i) + errpoint.count(i - 1) + errpoint.count(i - 2) ==
          errpoint.size()) {
        cout << "YES";
        goto successful;
      }
    }
    if (errpoint.size() == 1 && errpoint.count(n - 3)) {
      cout << "YES";
      goto successful;
    }
    cout << "NO";
  successful:;
    cout.put('\n');
  }
  return 0;
}