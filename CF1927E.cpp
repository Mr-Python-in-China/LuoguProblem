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
    size_t n, k;
    cin >> n >> k;
    vector<ui> a(n);
    ui x = 1;
    for (ui i = 0; i < k; i += 2)
      for (ui j = i; j < n; j += k) a[j] = x++;
    x = n;
    for (ui i = 1; i < k; i += 2)
      for (ui j = i; j < n; j += k) a[j] = x--;
    for (ui& i : a) cout << i << ' ';
    cout.put('\n');
  }
  return 0;
}