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
    size_t k, q;
    cin >> k >> q;
    vector<ui> a(k);
    for (ui& i : a) cin >> i;
    while (q--) {
      ui n;
      cin >> n;
      cout << min(a.front() - 1, n) << ' ';
    }
    cout.put('\n');
  }
  return 0;
}