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
  ui k;
  cin >> n >> k;
  vector<ui> a(n);
  for (ui &i : a) cin >> i;
  vector<pair<bool, bool>> f(k + 1);
  for (ui i = 0; i <= k; ++i)
    for (ui j : a)
      if (i >= j)
        f[i].first |= !f[i - j].second, f[i].second |= !f[i - j].first;
  cout << (f[k].first ? "First" : "Second");
  return 0;
}