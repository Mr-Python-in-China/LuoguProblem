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
    string a, b, c;
    cin >> n >> a >> b >> c;
    for (size_t i = 0; i < n; ++i)
      if (a[i] == b[i] && a[i] != c[i] ||
          a[i] != b[i] && c[i] != a[i] && c[i] != b[i])
        goto YES;
    cout << "NO\n";
    continue;
  YES:
    cout << "YES\n";
  }
  return 0;
}