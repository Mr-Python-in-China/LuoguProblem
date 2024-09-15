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
  vector<vector<int>> a(n, vector<int>(n));
  for (vector<int> &i : a)
    for (int &j : i) cin >> j;
  vector<li> s(1 << n);
  for (ui b = 0; b < (1u << n); ++b) {
    s[b] = 0;
    for (size_t i = 0; i < n; ++i)
      for (size_t j = i + 1; j < n; ++j)
        if ((b & (1u << i)) && (b & (1u << j))) s[b] += a[i][j];
    for (uli c = (b - 1) & b; c; c = (c - 1) & b)
      s[b] = max(s[b], s[c] + s[(~c) & b]);
  }
  cout << s.back();
  return 0;
}