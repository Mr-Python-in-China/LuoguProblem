#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string s;
  uli n;
  cin >> s >> n;
  --n;
  for (__int128 i = (__int128(1) << 64) * s.size(); i >= s.size(); i >>= 1)
    if (i <= n) n = (n - 1) % i;
  cout << s[n];
  return 0;
}