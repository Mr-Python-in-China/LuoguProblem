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
  size_t n, m, q;
  fin >> n >> m >> q;
  vector<vector<pair<size_t, int>>> mp(n);
  while (m--) {
    size_t x, y;
    ui z;
    fin >> x >> y >> z;
    --x, --y;
    mp[x].emplace_back(y, z), mp[y].emplace_back(x, -z);
  }
  vector<size_t> inGroup(n, ~0);
  vector<li> dis(n);
  vector<bool> groupType;
  for (size_t s = 0; s < n; ++s)
    if (!~inGroup[s]) {
      queue<size_t> q({s});
      inGroup[s] = groupType.size();
      groupType.emplace_back(false);
      while (!q.empty()) {
        size_t p = q.front();
        q.pop();
        for (auto const& i : mp[p]) {
          li d = dis[p] + i.second;
          if (!~inGroup[i.first])
            inGroup[i.first] = inGroup[s], dis[i.first] = d,
            q.emplace(i.first);
          else if (d != dis[i.first])
            groupType.back() = true;
        }
      }
    }
  while (q--) {
    size_t x, y;
    fin >> x >> y;
    --x, --y;
    if (inGroup[x] != inGroup[y])
      fout << "nan\n";
    else if (groupType[inGroup[x]])
      fout << "inf\n";
    else
      fout << dis[y] - dis[x] << '\n';
  }
  return 0;
}