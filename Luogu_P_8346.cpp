#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
array<char,256*1024*1024> buf;
void dfs(size_t p, vector<multiset<size_t>>& s, vector<vector<size_t>>& t,
         vector<bool>& vis) {
  if (s[p].size() != 1) return;
  vis[p] = true;
  size_t q = *s[p].begin();
  for (size_t i : t[q]) s[i].erase(s[i].find(q));
  for (size_t i : t[q]) dfs(i, s, t, vis);
  t[q].clear();
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  
  size_t T;
  fin >> T;
  while (T--) {
    size_t n, m;
    fin >> n >> m;
    vector<multiset<size_t>> s(n);
    vector<vector<size_t>> t(n);
    while (m--) {
      size_t x, y;
      fin >> x >> y;
      --x, --y;
      s[x].emplace(y), t[y].emplace_back(x);
    }
    vector<bool> vis(n);
    for (size_t i = 0; i < n; ++i) dfs(i, s, t, vis);
    fout << (count(vis.begin(), vis.end(), false) ? "Merry\n" : "Renko\n");
  }
  return 0;
}