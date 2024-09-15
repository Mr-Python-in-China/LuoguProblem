#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
unsigned short int constexpr P = 10007;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  array<vector<vector<size_t>>, 2> c(
      {vector<vector<size_t>>(m), vector<vector<size_t>>(m)});
  for (size_t i = 0; i < n; ++i) {
    size_t col;
    cin >> col;
    c[i & 1][--col].push_back(i);
  }
  uli ans = 0;
  for (vector<vector<size_t>>& i : c)
    for (vector<size_t>& j : i) {
      ui s = 0;
      for (size_t k : j) s += a[k];
      for (size_t k : j)
        (ans += (uli(j.size() - 1) * (k + 1) * a[k] + (k + 1) * (s - a[k]))) %=
            P;
    }
  cout << ans;
  return 0;
}