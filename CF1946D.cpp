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
    size_t n;
    ui x;
    cin >> n >> v;
    ui highbit_v = v ? 1 : 1 << (31 - __builtin_clz(x));
    vector<ui> a(0);
    for (size_t i = 0; i < n; ++i) {
      ui x;
      cin >> x;
      a.back() ^= x;
      if ((x & ~(highbit_v)) == 0) a.push_back(0);
    }
    if (a.back()) {
      cout << "-1";
      continue;
    }
  }
  return 0;
}