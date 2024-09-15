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
    ui a, b, l;
    cin >> a >> b >> l;
    set<ui> k;
    for (ui i = 1; i <= l; i *= a)
      for (ui j = 1; uli(i) * j <= l; j *= b)
        if (l % (i * j) == 0) k.insert(l / (i * j));
    cout << k.size() << '\n';
  }
  return 0;
}