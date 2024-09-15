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
    li f;
    ui a, b;
    cin >> n >> f >> a >> b;
    ui lst = 0;
    for (size_t i = 0; i < n; ++i) {
      ui now;
      cin >> now;
      f -= min<uli>(a * uli(now - lst), b);
      lst = now;
    }
    cout << (f > 0 ? "YES\n" : "NO\n");
  }
  return 0;
}