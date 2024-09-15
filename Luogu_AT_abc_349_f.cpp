#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  uli m;
  cin >> n >> m;
  unordered_map<uli, unsigned char> mz;
  {
    uli x = m;
    for (uli i = 2; i * i <= x; ++i)
      while (x % i == 0) x /= i, ++mz[i];
    if (x > 1) ++mz[x];
  }
  unordered_map<uli, size_t> k;
  while (n--) {
    uli x;
    cin >> x;
    if (m % x == 0) ++k[x];
  }

  return 0;
}