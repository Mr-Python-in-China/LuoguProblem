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
    cin >> n;
    vector<ui> a(n);
    for (ui &i : a) cin >> i;
    if (count(a.begin(), a.end(), a.front()) == n)
      cout << "NO\n";
    else if (count(a.begin(), a.end(), a.front()) == 1) {
      cout << "YES\n";
      for (size_t i = 1; i < n; ++i) cout.put('B');
      cout << "R\n";
    } else {
      cout << "YES\n";
      cout.put('R');
      for (size_t i = 1; i < n; ++i) cout.put('B');
      cout.put('\n');
    }
  }
  return 0;
}