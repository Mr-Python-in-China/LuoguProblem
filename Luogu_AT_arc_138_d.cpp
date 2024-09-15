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
  ui n, k;
  fin >> n >> k;
  vector<ui> s(n), d;
  for (ui b = 0; b < (1u << n); ++b)
    if (__builtin_popcount(b) == k) {
      ui x = b;
      for (ui i = n - 1; i < n; --i)
        if ((x >> i) & 1) {
          if (!s[i]) {
            s[i] = x;
            d.emplace_back(b);
            break;
          }
          x ^= s[i];
        }
    }
  if (d.size() == n) {
    fout << "Yes\n";
    ui x = 0;
    for (ui i = 0; i < (1u << n); x ^= d[__builtin_ctz(++i)]) fout << x << ' ';
  } else
    fout << "No";
  return 0;
}