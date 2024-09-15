#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui K = 32;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, k;
  cin >> n >> m >> k;
  array<vector<size_t>, K> st;
  st.fill(vector<size_t>(n));
  iota(st[0].begin(), st[0].end(), size_t(0));
  while (m--) {
    size_t l, r;
    cin >> l >> r;
    reverse(st[0].begin() + --l, st[0].begin() + r);
  }
  for (size_t i = 1; i < K; ++i)
    for (size_t j = 0; j < n; ++j) st[i][j] = st[i - 1][st[i - 1][j]];
  vector<size_t> ans(n);
  iota(ans.begin(), ans.end(), size_t(0));
  for (size_t i = 0; i < K; ++i)
    if (k & (1 << i))
      for (size_t j = 0; j < n; ++j) ans[j] = st[i][ans[j]];
  for (size_t i : ans) cout << i + 1 << '\n';
  return 0;
}