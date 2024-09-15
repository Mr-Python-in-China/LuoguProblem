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
  ui l, r;
  fin >> l >> r;
  vector<vector<pair<size_t, uli>>> mp(r - l + 1);
  for (ui p = 1; p <= 1e6; ++p) {
    ui st = (l + p - 1) / p * p;
    for (ui x = st + p; x <= r; x += p)
      mp[x - l].emplace_back(st - l, (uli)x * st / __gcd(x, st)),
          mp[st - l].emplace_back(x - l, (uli)x * st / __gcd(x, st));
  }
  priority_queue<pair<uli, size_t>, vector<pair<uli, size_t>>,
                 greater<pair<uli, size_t>>>
      q;
  uli ans = 0;
  q.emplace(0, r - l);
  vector<bool> vis(r - l + 1);
  while (!q.empty()) {
    pair<uli, size_t> t = q.top();
    q.pop();
    size_t p = t.second;
    if (vis[p]) continue;
    ans += t.first;
    vis[p] = true;
    for (auto const& i : mp[p]) q.emplace(i.second, i.first);
  }
  fout << ans;
  return 0;
}