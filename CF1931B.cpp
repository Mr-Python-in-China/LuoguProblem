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
    ui sum = 0;
    for (ui& i : a) cin >> i, sum += i;
    sum /= n;
    for (vector<ui>::iterator it = a.begin(), jt = next(it); jt < a.end();
         ++it, ++jt)
      if (*it < sum) {
        cout << "NO\n";
        goto NO;
      } else
        *jt += *it - sum, *it -= sum;
    cout << "YES\n";
  NO:;
  }
  return 0;
}