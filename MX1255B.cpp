#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> pair<T, T> orderedPair(T const &x, T const &y) {
  return make_pair(min(x, y), max(x, y));
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t ID, T;
  fin >> ID >> T;
  while (T--) {
    size_t n, m;
    ui k;
    fin >> n >> m >> k;
    vector<ui> arr;
    {
      map<pair<size_t, size_t>, ui> edge;
      vector<set<size_t>> mp(n);
      for (size_t i = 0; i < m; ++i) {
        size_t x, y;
        ui v;
        fin >> x >> y >> v;
        --x, --y;
        edge[{min(x, y), max(x, y)}] += v;
        mp[x].emplace(y), mp[y].emplace(x);
      }
      if (edge.size() == n) {
        queue<size_t> q;
        for (size_t i = 0; i < n; ++i)
          if (mp[i].size() == 1) q.push(i);
        while (!q.empty()) {
          size_t const p = q.front();
          q.pop();
          assert(mp[p].size() == 1);
          size_t const i = *mp[p].begin();
          mp[p].erase(i), mp[i].erase(p);
          if (mp[i].size() == 1) q.push(i);
        }
        auto pt = edge.end(), qt = edge.end();
        for (auto it = edge.begin(); it != edge.end(); ++it)
          if (mp[it->first.first].size() == 2 &&
              mp[it->first.second].size() == 2)
            if (pt == edge.end() || it->second < pt->second)
              qt = pt, pt = it;
            else if (qt == edge.end() || it->second < qt->second)
              qt = it;
        assert(pt != edge.end() && qt != edge.end());
        arr.emplace_back(pt->second + qt->second);
        edge.erase(pt), edge.erase(qt);
      } else
        assert(edge.size() == n - 1);
      for (auto const &i : edge) arr.emplace_back(i.second);
    }
    ui l = 1, r = numeric_limits<ui>::max();
    while (l < r) {
      ui mid = (r - l + 1) / 2 + l;
      uli sum = 0;
      for (ui i : arr)
        if (i < mid) sum += mid - i;
      sum <= k ? l = mid : r = mid - 1;
    }
    fout << l << '\n';
  }
  return 0;
}