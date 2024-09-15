#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 998244353;
ui solve(vector<ui> const &prefixSum, ui k) {
  ui ans = 0;
  for (vector<ui>::const_iterator it = prefixSum.cbegin();
       it < prefixSum.cend(); ++it)
    if ((ans += upper_bound(it, prefixSum.cend(), *it + k) -
                lower_bound(it, prefixSum.cend(), *it + k)) >= P)
      ans -= P;
  return ans;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  ui k;
  fin >> n >> m >> k;
  vector<ui> s1(n + 1), s2(m + 1);
  for (size_t i = 0; i < n; ++i) {
    char c;
    fin >> c;
    s1[i + 1] = s1[i] + (c == '1');
  }
  for (size_t i = 0; i < m; ++i) {
    char c;
    fin >> c;
    s2[i + 1] = s2[i] + (c == '1');
  }
  vector<pair<ui, ui>> d;
  for (ui i = 1; i * i < k; ++i)
    if (k % i == 0) d.emplace_back(i, k / i), d.emplace_back(k / i, i);
  if (ui(sqrt(k)) * ui(sqrt(k)) == k) d.emplace_back(ui(sqrt(k)), ui(sqrt(k)));
  ui ans = 0;
  for (pair<ui, ui> const &i : d)
    ans = (ans + (uli)solve(s1, i.first) * (uli)solve(s2, i.second)) % P;
  fout << ans;
  return 0;
}