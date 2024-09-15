#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  fin >> T;
  while (T--) {
    size_t n;
    ui k;
    fin >> n >> k;
    vector<ui> a(n);
    for (ui &i : a) fin >> i;
    sort(a.begin(), a.end(), greater<ui>());
    for (size_t i = 1; i < n && k; i += 2) {
      ui d = min(k, a[i - 1] - a[i]);
      a[i] += d, k -= d;
    }
    li ans = 0;
    for (size_t i = 0; i < n; i += 2) ans += a[i];
    for (size_t i = 1; i < n; i += 2) ans -= a[i];
    fout << ans << '\n';
  }
  return 0;
}