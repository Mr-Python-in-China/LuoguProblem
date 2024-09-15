#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  map<string, size_t> id;
  vector<vector<size_t>> mp;
  for (string s, t; cin >> s >> t;) {
    auto sp = id.find(s);
    if (sp == id.end()) sp = id.emplace(s, mp.size()).first, mp.emplace_back();
    auto tp = id.find(t);
    if (tp == id.end()) tp = id.emplace(t, mp.size()).first, mp.emplace_back();
    mp[sp->second].emplace_back(tp->second),
        mp[tp->second].emplace_back(sp->second);
  }
  if (mp.empty()) cout << "Possible", exit(0);
  vector<bool> vis(mp.size());
  vis[0] = true;
  queue<size_t> q({0});
  while (!q.empty()) {
    size_t p = q.front();
    q.pop();
    for (size_t i : mp[p])
      if (!vis[i]) vis[i] = true, q.emplace(i);
  }
  cout << (count(vis.begin(), vis.end(), true) == vis.size() &&
                   count_if(mp.begin(), mp.end(),
                            [](vector<size_t> const& c) {
                              return c.size() % 2 == 1;
                            }) <= 2
               ? "Possible"
               : "Impossible");
  return 0;
}