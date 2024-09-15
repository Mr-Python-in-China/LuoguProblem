#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui a, b;
  cin >> n >> a >> b;
  set<ui> d;
  for (size_t i = 0; i < n; ++i) {
    size_t x;
    cin >> x;
    d.insert((--x) % (a + b));
  }
  for (set<ui>::iterator it = d.begin(), jt = next(it); jt != d.end();
       ++jt, ++it)
    if (*jt - *it > b) cout << "Yes", exit(0);
  if (*d.begin() + (a + b) - *d.rbegin() > b) cout << "Yes", exit(0);
  cout << "No";
  return 0;
}