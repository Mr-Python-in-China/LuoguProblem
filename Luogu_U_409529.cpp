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
    ui k;
    cin >> n >> k;
    vector<string> kpow({to_string(k)});
    if (k > 1)
      while (__uint128_t(stoll(kpow.back())) * k <= numeric_limits<uli>::max())
        kpow.push_back(to_string(stoll(kpow.back()) * k));
    vector<pair<ui, ui>> ans;
    for (size_t i = 1; i <= n; ++i) {
      string month = to_string(i);
      ui x;
      cin >> x;
      if (k > 1)
        for (string const& j : kpow)
          if (month.size() < j.size() &&
              equal(month.cbegin(), month.cend(), j.cbegin())) {
            string k(j.cbegin() + month.size(), j.cend());
            if (k.front() != '0' && stoll(k) <= x)
              ans.emplace_back(i, stoll(k));
          }
    }
    cout << ans.size() << '\n';
    for (pair<ui, ui> i : ans) cout << i.first << ' ' << i.second << '\n';
  }
  return 0;
}