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
  size_t n, W;
  cin >> n >> W;
  array<uli, size_t(1e3) * 100 + 1> f;
  f.fill(numeric_limits<uli>::max() / 2);
  f[0] = 0;
  while (n--) {
    ui w, v;
    cin >> w >> v;
    for (ui i = f.size() - 1; i >= v; --i) f[i] = min(f[i], f[i - v] + w);
  }
  cout << f.rend() -
              find_if(f.rbegin(), f.rend(), [&](uli x) { return x <= W; }) - 1;
  return 0;
}