#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, k;
  cin >> n >> m >> k;
  vector<vector<bool>> a(n, vector<bool>(m));
  size_t x = 0, y = 0, d = 0;
  while (k--) {
    a[x][y] ? --d : ++d;
    a[x][y].flip();
    (d += 4) %= 4;
    d == 0 ? --x : d == 1 ? ++y : d == 2 ? ++x : d == 3 ? --y : throw;
    (x += n) %= n, (y += m) %= m;
  }
  for (vector<bool>& i : a) {
    for (vector<bool>::reference j : i) cout.put(j ? '#' : '.');
    cout.put('\n');
  }
  return 0;
}