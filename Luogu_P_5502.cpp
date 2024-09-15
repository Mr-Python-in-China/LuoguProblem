#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned long long int;
using uli = unsigned long long int;
using li = long long int;
template <typename _EuclideanRingElement>
_EuclideanRingElement gcd(_EuclideanRingElement __m,
                          _EuclideanRingElement __n) {
  while (__n != 0) {
    _EuclideanRingElement __t = __m % __n;
    __m = __n;
    __n = __t;
  }
  return __m;
}

uli f(vector<ui>::const_iterator l, vector<ui>::const_iterator r,
      size_t const& k) {
  if (r - l < k) return 0;
  if (r - l == 1) return *l;
  vector<ui>::const_iterator mid = ((r - l) >> 1) + l;
  uli ans = max(f(l, mid, k), f(mid, r, k));
  {
    uli s = 1;
    ui g = *mid;
    vector<ui>::const_iterator it = mid, jt = mid;
    while (jt < r) {
      while (l <= it && gcd(*it, g) == g) s += 1, --it;
      while (jt < r && gcd(*jt, g) == g) s += 1, ++jt;
      s -= 1, s -= 1;
      ++it, --jt;
      if (jt - it + 1 >= k) ans = max(ans, s * g);
      g = gcd(g, *++jt);
      s += 1;
    }
  }
  {
    uli s = 1;
    ui g = *mid;
    vector<ui>::const_iterator it = mid, jt = mid;
    while (l <= it) {
      while (l <= it && gcd(*it, g) == g) s += 1, --it;
      while (jt < r && gcd(*jt, g) == g) s += 1, ++jt;
      s -= 1, s -= 1;
      ++it, --jt;
      if (jt - it + 1 >= k) ans = max(ans, s * g);
      g = gcd(g, *--it);
      s += 1;
    }
  }
  return ans;
}
int main(void) {
  // freopen("intelligence.in","r",stdin),freopen("intelligence.out","w",stdout);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  cout << f(a.begin(), a.end(), 1);
  return 0;
}