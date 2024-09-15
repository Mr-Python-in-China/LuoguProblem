#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  unsigned short int m;
  cin >> n >> m;
  vector<ui> cnt(1 << m);
  for (size_t i = 0; i < n; ++i) {
    size_t c;
    cin >> c;
    ui b = 0;
    while (c--) {
      ui x;
      cin >> x;
      b |= (1 << --x);
    }
    ++cnt[b];
  }
  return 0;
}