#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<vector<char>> a(n, vector<char>(n));
  for (vector<char>& i : a)
    for (char& j : i) cin >> j;
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < n; ++j) {
      char c;
      cin >> c;
      if (c != a[i][j]) cout << i + 1 << ' ' << j + 1;
    }
  return 0;
}