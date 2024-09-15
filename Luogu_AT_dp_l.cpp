#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<ui> a(n);
  for (ui &i : a) cin >> i;
  vector<vector<li>> f(n + 1);
  for (size_t i = 0; i <= n; ++i) f[i].resize(n - i + 1);
  for (size_t len = 1; len <= n; ++len)
    for (size_t i = 0; i + len <= n; ++i)
      f[i][len] =
          max(li(a[i + len - 1]) - f[i][len - 1], li(a[i]) - f[i + 1][len - 1]);
  cout << f[0][n];
  return 0;
}