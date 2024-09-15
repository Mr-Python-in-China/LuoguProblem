#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<vector<size_t>>;
using ulli = __uint128_t;
struct fraction {
  ulli a, b;  // a/b
  fraction(void): fraction(0) {}
  fraction(ulli x): a(x), b(1) {}
  void yf(void) {  // 约分
    if (a) {
      ulli gcd = __gcd(a, b);
      a /= gcd, b /= gcd;
    } else
      b = 1;
  }
  fraction& operator+=(fraction const& x) {
    ulli lcm = b / __gcd<ulli>(b, x.b) * x.b;
    (a *= lcm / b) += lcm / x.b * x.a;
    b = lcm;
    yf();
    return *this;
  }
  fraction& operator/=(ulli x) {
    if (a) {
      ulli gcd = __gcd<ulli>(a, x);
      a /= gcd;
      b *= (x / gcd);
    }
    return *this;
  }
  fraction operator/(ulli x) {
    fraction tmp = *this;
    return tmp /= x;
  }
};
ostream& operator<<(ostream& out, ulli x) {
  if (x > 9) out << x / 10;
  return out << char('0' + x % 10);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  graph mp(n);
  vector<size_t> indeg(n);
  for (vector<size_t>& i : mp) {
    size_t d;
    cin >> d;
    i.resize(d);
    for (size_t& j : i) cin >> j, ++indeg[--j];
  }
  queue<size_t> q;
  vector<fraction> ans(n);
  for (size_t i = 0; i < n; i++)
    if (!indeg[i]) q.push(i), ans[i] = 1;
  while (!q.empty()) {
    size_t p = q.front();
    q.pop();
    fraction waterout = ans[p] / ulli(mp[p].size());
    for (size_t const& j : mp[p]) {
      if (!--indeg[j]) q.push(j);
      ans[j] += waterout;
    }
  }
  for (size_t j = 0; j < n; j++)
    if (mp[j].empty()) cout << ans[j].a << ' ' << ans[j].b << '\n';
  return 0;
}