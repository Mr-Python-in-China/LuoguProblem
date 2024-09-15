#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr uli P = 1000000000000002493;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<uli> a(n);
  for (uli& i : a) {
    string s;
    cin >> s;
    for (char j : s) i = (__uint128_t(i) * 10 + j - '0') % P;
  }
  sort(a.begin(), a.end());
  ui ans = 0;
  for (vector<uli>::const_iterator it = a.cbegin(); it < a.cend(); ++it)
    for (vector<uli>::const_iterator jt = a.cbegin(); jt < a.cend(); ++jt)
      ans += upper_bound(a.cbegin(), a.cend(), __uint128_t(*it) * *jt % P) -
             lower_bound(a.cbegin(), a.cend(), __uint128_t(*it) * *jt % P);
  cout << ans;
  return 0;
}