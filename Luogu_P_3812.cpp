#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  fin >> n;
  array<uli, 50> d = {};
  for (size_t t = 0; t < n; ++t) {
    uli x;
    fin >> x;
    for (size_t i = d.size() - 1; i < d.size(); --i)
      if ((x >> i) & 1) {
        if (d[i] == 0) {
          d[i] = x;
          break;
        } else
          x ^= d[i];
      }
  }
  uli ans = 0;
  for (size_t i = d.size() - 1; i < d.size(); --i)
    if (!((ans >> i) & 1)) ans ^= d[i];
  fout << ans;
  return 0;
}