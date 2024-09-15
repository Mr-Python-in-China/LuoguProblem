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
    size_t n, m;
    cin >> n >> m;
    vector<vector<ui>> a(n, vector<ui>(m));
    for (vector<ui> &i : a)
      for (ui &j : i) cin >> j;
    if (n == 1 && m == 1) {
      cout << "-1\n";
      continue;
    }
    rotate(a.begin(), a.begin() + 1, a.end());
    for (vector<ui> &i : a) rotate(i.begin(), i.begin() + 1, i.end());
    for (vector<ui> const &i : a) {
      for (ui const &j : i) cout << j << ' ';
      cout << '\n';
    }
  }
  return 0;
}