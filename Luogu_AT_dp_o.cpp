#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 1e9 + 7;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n;
  cin >> n;
  vector<vector<bool>> a(n, vector<bool>(n));
  for (vector<bool> &i : a)
    for (auto j : i) {
      char c;
      cin >> c;
      j = c == '1';
    }
  vector<ui> f(1u << n);
  f[0] = 1;
  for (ui i = 0; i < n; ++i)
    for (ui b = 0; b < (1 << n); ++b)
      if (__builtin_popcount(b) == i)
        for (ui j = 0; j < n; ++j)
          if (!(b & (1u << j)) && a[i][j])
            if ((f[b | (1u << j)] += f[b]) >= P) f[b | (1u << j)] -= P;
  cout << f.back();
  return 0;
}