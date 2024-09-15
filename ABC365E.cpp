#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  array<size_t, 32> f = {};
  uli ans = 0;
  for (size_t i = 0; i < n; ++i) {
    ui x;
    cin >> x;
    for (size_t j = 0; j < f.size(); ++j) {
      if ((x >> j) & 1) f[j] = i - f[j] + 1;
      ans += (1ull << j) * f[j];
    }
    ans -= x;
  }
  cout << ans;
  return 0;
}