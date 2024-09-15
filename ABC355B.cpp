#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<usi> a(n), b(m);
  for (usi &i : a) cin >> i;
  for (usi &i : b) cin >> i;
  vector<usi> c(a);
  c.insert(c.end(), b.begin(), b.end());
  sort(c.begin(), c.end());
  for (vector<usi>::const_iterator it = c.cbegin(), jt = next(it);
       jt < c.cend(); ++it, ++jt)
    if (count(a.cbegin(), a.cend(), *it) && count(a.cbegin(), a.cend(), *jt))
      cout << "Yes", exit(0);
  cout << "No";
  return 0;
}