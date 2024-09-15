#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = long long int;
using uli = long long int;
using li = long long int;
ostream& operator<<(ostream& out, __int128_t x) {
  if (x < 0) out.put('-'), x = -x;
  if (x / 10) out << x / 10;
  return out.put(x % 10 + '0');
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    unsigned int b, x;
    cin >> n >> b >> x;
    vector<unsigned int> a(n);
    for (unsigned int& i : a) cin >> i;
    ui l = 1, r = *max_element(a.begin(), a.end());
    auto f = [&](ui t) {
      uli ans = -(t - 1) * x;
      for (ui i : a) {
        ui k = min(t, i);
        ui c = i % k, d = (i + k - 1) / k;
        if (c == 0) c = k;
        for (ui j = 0; j < c; ++j) ans += d * (i -= d) * b;
        for (ui j = c; j < k; ++j) ans += (d - 1) * (i -= d - 1) * b;
      }
      return ans;
    };
    while (l < r) {
      ui mid = (l + r) / 2;
      f(mid) > f(mid + 1) ? r = mid : l = mid + 1;
    }
    cout << f(l) << '\n';
  }
  return 0;
}