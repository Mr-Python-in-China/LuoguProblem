#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui ma, mb;
  cin >> n >> ma >> mb;
  vector<bool> a(2 * n);
  for (vector<bool>::reference i : a) {
    char c;
    cin >> c;
    i = c == '(';
  }
  int d = 0;
  for (bool i : a) i ? ++d : --d;
  if (d > 0) {
    d = -d;
    reverse(a.begin(), a.end());
    for (vector<bool>::reference i : a) i = !i;
  }
  int e = 0, f = 0;
  size_t p = 0, q = 2 * n;
  size_t ca = 0, cb = 0;
  for (; p < q; ++p) {
    a[p] ? ++e : --e;
    if (e < 0) {
      if (d < 0)
        a[p] = !a[p], d += 2, ++cb;
      else {
        while (f <= 0) a[--q] ? ++f : --f;
        swap(a[p], a[q]), ++ca;
      }
      e += 2;
    }
  }
  cout << uli(ca) * min({ma, 2 * mb}) + uli(cb) * mb;
  return 0;
}