#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  int c;
  cin >> n >> c;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  vector<li> f(n);
  f[0] = a[0];
  for (size_t i = 1; i < n; ++i)
    f[i] = a[i] + (c > 0 ? max(f[i - 1], 0ll) : min(f[i - 1], 0ll));
  li ans = 0;
  for (li i : f) ans = c > 0 ? max(ans, i) : min(ans, i);
  cout << accumulate(a.begin(), a.end(), li(0)) + ans * (c - 1);
  return 0;
}