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
  vector<unsigned short int> h(n);
  for (auto &i : h) cin >> i;
  vector<ui> f(n, numeric_limits<ui>::max());
  f[0] = 0;
  for (size_t i = 0; i + 2 < n; ++i)
    f[i + 1] = min(f[i + 1], f[i] + max(h[i], h[i + 1]) - min(h[i], h[i + 1])),
          f[i + 2] =
              min(f[i + 2], f[i] + max(h[i], h[i + 2]) - min(h[i], h[i + 2]));
  f[n - 1] = min(f[n - 1],
                 f[n - 2] + max(h[n - 2], h[n - 1]) - min(h[n - 2], h[n - 1]));
  cout << f.back();
  return 0;
}