#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<vector<size_t>>;
void init_fa(size_t p, graph const &mp, vector<size_t> &fa) {
  fa[p] = ~0;
  for (size_t i : mp[p])
    if (~fa[i]) {
      init_fa(i, mp, fa);
      fa[i] = p;
    }
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, q;
    cin >> n >> q;
    vector<bool> color(n);
    for (vector<bool>::reference i : color) {
      char c;
      cin >> c;
      i = c == '1';
    }
    graph mp(n);
    for (size_t i = 1; i < n; ++i) {
      size_t x, y;
      cin >> x >> y;
      --x, --y;
      mp[x].emplace_back(y), mp[y].emplace_back(x);
    }
    color.emplace_back(false);
    vector<size_t> fa(n), szcnt(n + 1);
    init_fa(0, mp, fa);
    for (size_t i = 0; i < n; ++i) {
      if (!~fa[i]) fa[i] = n;
      if (color[i]) ++szcnt[fa[i]];
    }
    size_t szcnt_1 = 0,
           total = accumulate(color.begin(), color.end(), size_t(0));
    set<size_t> szcnt_2pos;
    size_t white_szcnt_1pos = 0;
    for (size_t i = 0; i <= n; ++i)
      if (szcnt[i] == 1) {
        ++szcnt_1;
        if (!color[i]) ++white_szcnt_1pos;
      } else if (szcnt[i] == 2)
        szcnt_2pos.insert(i);
    while (q--) {
      size_t p;
      cin >> p;
      --p;
      if (szcnt[fa[p]] == 1) {
        --szcnt_1;
        if (!color[fa[p]]) --white_szcnt_1pos;
      } else if (szcnt[fa[p]] == 2)
        szcnt_2pos.erase(fa[p]);
      if (color[p]) {
        --szcnt[fa[p]];
        color[p] = false;
        --total;
        if (szcnt[p] == 1) ++white_szcnt_1pos;
      } else {
        ++szcnt[fa[p]];
        if (szcnt[p] == 1) --white_szcnt_1pos;
        color[p] = true;
        ++total;
      }
      if (szcnt[fa[p]] == 1) {
        ++szcnt_1;
        if (!color[fa[p]]) ++white_szcnt_1pos;
      } else if (szcnt[fa[p]] == 2)
        szcnt_2pos.insert(fa[p]);
      if (szcnt_2pos.size() > 1 || total != szcnt_1 + szcnt_2pos.size() * 2) {
        cout << "No\n";
        continue;
      }
      if (szcnt_2pos.size() == 1 &&
          (!color[*szcnt_2pos.cbegin()] || color[fa[*szcnt_2pos.cbegin()]])) {
        cout << "No\n";
        continue;
      }
      if (white_szcnt_1pos != 1) {
        cout << "No\n";
        continue;
      }
      cout << "Yes\n";
    }
  }
  return 0;
}