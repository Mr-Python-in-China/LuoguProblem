#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct Edge {
  size_t from, to;
  ui w;
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  fin >> T;
  while (T--) {
    size_t n, m;
    ui k;
    fin >> n >> m >> k;
    vector<Edge> edges(m);
    vector<vector<reference_wrapper<Edge>>> mp(n);
    for (Edge& i : edges) {
      fin >> i.from >> i.to, --i.from, --i.to;
      mp[i.from].emplace_back(i);
    }
    if (k > 1) {
      vector<ui> dis(n, numeric_limits<ui>::max() / 2);
      priority_queue<pair<ui, size_t>, vector<pair<ui, size_t>>,
                     greater<pair<ui, size_t>>>
          q;
      dis[0] = 0, q.emplace(0, 0);
      while (!q.empty()) {
        size_t p = q.top().second;
        q.pop();
        for (auto const& i : mp[p]) {
          if (dis[i.get().to] == numeric_limits<ui>::max() / 2)
            i.get().w = 1, q.emplace(dis[i.get().to] = dis[p] + 1, i.get().to);
          else if (dis[p] + 2 > dis[i.get().to])
            i.get().w = 2;
          else
            throw;
        }
      }
      fout << "Yes\n";
      for (Edge const& i : edges) fout << i.w << ' ';
      fout << '\n';
    } else {
      vector<ui> dis(n, numeric_limits<ui>::max() / 2);
      priority_queue<pair<ui, size_t>, vector<pair<ui, size_t>>,
                     greater<pair<ui, size_t>>>
          q;
      dis[0] = 0, q.emplace(0, 0);
      while (!q.empty()) {
        size_t p = q.top().second;
        q.pop();
        for (auto const& i : mp[p]) {
          if (dis[i.get().to] == numeric_limits<ui>::max() / 2)
            i.get().w = 1, q.emplace(dis[i.get().to] = dis[p] + 1, i.get().to);
          else if (dis[i.get().to] == dis[p] + 1) {
            fout << "No\n";
            goto failed;
          } else
            i.get().w = 1;
        }
      }
      fout << "Yes\n";
      for (Edge const& i : edges) fout << i.w << ' ';
    failed:;
    }
  }
  return 0;
}