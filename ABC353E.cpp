#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr uli P = 1000000000000000079;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  unordered_map<uli, size_t> cnt;
  uli ans = 0;
  for (size_t t = 0; t < n; ++t) {
    string s;
    cin >> s;
    vector<uli> h = {0};
    for (char i : s) h.push_back((h.back() * __uint128_t(26) + i) % P);
    uli k = 0;
    for (size_t i = h.size() - 1; i < h.size(); --i)
      ans += (cnt[h[i]] - k) * i, k += cnt[h[i]] - k, ++cnt[h[i]];
  }
  cout << ans;
  return 0;
}