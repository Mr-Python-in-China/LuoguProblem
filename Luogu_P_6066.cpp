#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
list<size_t> eulerPath(size_t p, vector<vector<size_t>>& mp) {
  list<size_t> res;
  while (!mp[p].empty()) {
    size_t i = mp[p].back();
    mp[p].pop_back();
    res.splice(res.end(), eulerPath(i, mp));
  }
  res.emplace_back(p);
  return res;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  fin >> n >> m;
  vector<vector<size_t>> mp(n);
  while (m--) {
    size_t x, y;
    fin >> x >> y;
    --x, --y;
    mp[x].emplace_back(y), mp[y].emplace_back(x);
  }
  for (size_t i : eulerPath(0, mp)) fout << i + 1 << '\n';
  return 0;
}