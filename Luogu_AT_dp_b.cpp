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
  size_t n, k;
  cin >> n >> k;
  vector<unsigned short int> h(n);
  for (auto &i : h) cin >> i;
  vector<ui> f(n, numeric_limits<ui>::max() / 2);
  f[0] = 0;
  for (size_t i = 0; i < n; ++i)
    for (size_t j = i + 1; j < n && j - i <= k; ++j)
      f[j] = min(f[j], f[i] + max(h[i], h[j]) - min(h[i], h[j]));
  cout << f.back();
  return 0;
}