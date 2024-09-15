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
    size_t n, f, k;
    cin >> n >> f >> k;
    --f;
    vector<ui> a(n);
    for (ui &i : a) cin >> i;
    ui fav = a[f];
    sort(a.rbegin(), a.rend());
    cout << (k == n || a[k] < fav             ? "YES"
             : a[k - 1] == fav && a[k] == fav ? "MAYBE"
                                              : "NO")
         << '\n';
  }
  return 0;
}