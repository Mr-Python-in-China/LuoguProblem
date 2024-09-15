#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using uc = unsigned char;
using usi = unsigned short int;

int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  array<vector<vector<uc>>, 65536> d;
  vector<vector<uc>, usi> e;
  {
    vector<pair<uc, uc>> nxt(n, {255, numeric_limits<uc>::max()});
    while (m--) {
      usi a, b, c;
      cin >> a >> b >> c;
      --a, --b;
      if (nxt[b].second > c) nxt[b] = {a, c};
    }
    vector<bool> vis(n);
    for (uc i = 0; i < n; ++i)
      if (!vis[i]) {
        uc p = i;
        vector<uc> r;
        usi t = 0;
        while (p != 255) {
          r.emplace_back(p);
          vis[p] = true;
          t = (t << nxt[p].second) | 1;
          p = nxt[p].first;
        }
        d[t].push_back(r);
        e.emplace_back(r, t);
      }
  }

  return 0;
}