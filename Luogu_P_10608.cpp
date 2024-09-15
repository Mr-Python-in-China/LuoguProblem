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
  size_t n, m;
  fin >> n >> m;
  vector<pair<bool, bool>> d(n);
  for (auto& i : d) {
    char c;
    fin >> c;
    if (c == '_')
      i.first = true;
    else
      i.first = false, i.second = c == 'W';
  }
  size_t fst = ~0;
  while (m--) {
    char c;
    size_t p;
    fin >> c >> p;
    assert(d[--p].first);
    if (!~fst) fst = p;
    d[p].second = c == 'R';
  }
  size_t p = 0;
  while (p < n && d[p].first) ++p;
  if (p == n) d[p = fst].second = false;
  for (size_t i = p - 1; i < n; --i) d[i].second ^= d[i + 1].second;
  for (size_t i = p + 1; i < n; ++i)
    if (d[i].first) d[i].second ^= d[i - 1].second;
  size_t ans = 1;
  for (size_t i = 1; i < n; ++i) ans += d[i].second != d[i - 1].second;
  fout << ans;
  return 0;
}