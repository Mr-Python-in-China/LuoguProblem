#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T, typename = is_unsigned<T>>
constexpr T abs_minus(T const &a, T const &b) {
  return max(a, b) - min(a, b);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui c;
  fin >> n >> c;
  vector<ui> a(n);
  for (ui &i : a) fin >> i;
  vector<uli> f(*max_element(a.begin(), a.end()) + 1,
                numeric_limits<uli>::max() / 2);
  for (ui x = 0; x + a[0] < f.size(); ++x) f[a[0] + x] = (uli)x * x;
  for (size_t i = 1; i < n; ++i) {
    vector<uli> g(f.size(), numeric_limits<uli>::max() / 2);
    for (ui p = a[i - 1]; p < a.size(); ++p)
      for (ui x = 0; x + a[i] < g.size(); ++x)
        g[x + a[i]] = min(g[x + a[i]],
                          f[p] + (uli)x * x + (uli)c * abs_minus(x + a[i], p));
    f = g;
  }
  fout << *min_element(f.begin(), f.end());
  return 0;
}