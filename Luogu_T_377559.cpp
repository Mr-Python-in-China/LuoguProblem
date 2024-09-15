#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
bitset<size_t(1e6 + 1)> is_prime;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  is_prime.flip();
  is_prime.reset(0), is_prime.reset(1);
  for (size_t i = 2; i * i < is_prime.size(); i++)
    if (is_prime[i])
      for (size_t j = i * i; j < is_prime.size(); j += i) is_prime.reset(j);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, m;
    cin >> n >> m;
    vector<vector<ui>> arr(n, vector<ui>(m));
    for (vector<ui>& i : arr)
      for (ui& j : i) cin >> j;
    vector<vector<size_t>> ans(n, vector<size_t>(m));
    for (size_t j = 0; j < m; j++) ans[0][j] = is_prime[arr[0][j]];
    for (size_t i = 1; i < n; i++)
      for (size_t j = 0; j < n; j++)
        ans[i][j] = is_prime[arr[i][j]] ? ans[i - 1][j] + 1 : 0;
    for (vector<size_t> const& i : ans) {
      for (size_t const& j : i) cout << j << ' ';
      cout << '\n';
    }
  }
  return 0;
}