#include <bits/extc++.h>

#include <tr2/dynamic_bitset>
using namespace std;
namespace pbds = __gnu_pbds;
using tr2::dynamic_bitset;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  fin >> n >> m;
  vector<dynamic_bitset<>> mp(n, dynamic_bitset<>(n));
  for (size_t i = 0; i < n; ++i) mp[i].set(i);
  while (m--) {
    size_t x, y;
    fin >> x >> y;
    --x, --y;
    mp[x].set(y);
  }
  size_t nq;
  fin >> nq;
  vector<pair<pair<size_t, size_t>, size_t>> q(nq);
  for (auto& i : q)
    fin >> i.first.first >> i.first.second, --i.first.first, --i.first.second,
        i.second = ~0;
  vector<dynamic_bitset<>> f(n, dynamic_bitset<>(n));
  for (size_t k = 0; k < n; ++k) {
    f[k] |= mp[k];
    for (size_t i = 0; i < n; ++i)
      if (mp[k].test(i)) f[k] |= f[i];
    for (size_t i = 0; i < n; ++i)
      if (f[i].test(k)) f[i] |= f[k];
    for (auto& i : q)
      if (!~i.second && i.first.first <= k && i.first.second <= k &&
          f[i.first.first].test(i.first.second))
        i.second = k;
  }
  for (auto const& i : q)
    (~i.second ? fout << i.second + 1 : fout << "-1") << '\n';
  return 0;
}