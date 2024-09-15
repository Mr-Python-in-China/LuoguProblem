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
  vector<ui> a(n);
  for (ui& i : a) fin >> i;
  vector<array<uli, 2>> f(n + 1, array<uli, 2>{});
  f[1][1] = a[0];
  for (size_t i = 1; i < n; ++i) {
    f[i + 1][0] = max(f[i][1], f[i - 1][1]) + a[i] * 2;
    f[i + 1][1] = max(f[i][0], f[i - 1][0]) + a[i];
  }
  fout << max(f.back()[0], f.back()[1]);
  return 0;
}