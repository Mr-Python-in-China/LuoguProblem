#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<li> a(n);
  for (li& i : a) cin >> i;
  li g = 0;
  for (vector<li>::iterator it = a.begin(), jt = next(it); jt < a.end();
       ++it, ++jt)
    g = __gcd(g, *jt - *it);
  g = abs(g);
  while (m--) {
    li x;
    cin >> x;
    cout << __gcd(g, x + a.front()) << ' ';
  }
  return 0;
}