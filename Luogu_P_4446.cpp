#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
vector<ui> prime(ui n) {
  vector<ui> res;
  vector<bool> vis(n + 1);
  vis[0] = vis[1] = true;
  for (ui i = 2; i * i <= n; ++i)
    if (!vis[i])
      for (ui j = i * 2; j <= n; j += i) vis[j] = true;
  for (ui i = 0; i <= n; ++i)
    if (!vis[i]) res.push_back(i);
  return res;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  vector<ui> primes = prime(2e6);
  vector<uli> primes_cbr(primes.begin(), primes.end());
  for (uli& i : primes_cbr) i = i * i * i;
  size_t T;
  cin >> T;
  while (T--) {
    uli n;
    cin >> n;
    uli s = 1;
    for (size_t i = 0; primes_cbr[i] * primes[i] <= n; ++i)
      while (n % primes_cbr[i] == 0) n /= primes_cbr[i], s *= primes[i];
    if (uli(cbrt((long double)n)) * cbrt((long double)n) *
            cbrt((long double)n) ==
        n)
      s *= cbrt((long double)n), n /= n;
    cout << s << '\n';
  }
  return 0;
}