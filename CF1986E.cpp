#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    ui k;
    cin >> n >> k;
    map<ui, vector<ui>> mod;
    for (size_t i = 0; i < n; ++i) {
      ui x;
      cin >> x;
      mod[x % k].emplace_back(x);
    }
    uli ans = 0;
    bool tag = false;
    for (pair<ui const, vector<ui>> &i : mod) {
      sort(i.second.begin(), i.second.end());
      if (i.second.size() % 2) {
        if (tag) {
          cout << "-1\n";
          goto failed;
        }
        vector<ui> f = {0}, g = {0};
        for (ui j = 0; j + 1 < i.second.size(); j += 2)
          f.emplace_back(f.back() + (i.second[j + 1] - i.second[j]) / k);
        for (ui j = i.second.size() - 2; j < i.second.size(); j -= 2)
          g.emplace_back(g.back() + (i.second[j + 1] - i.second[j]) / k);
        reverse(g.begin(), g.end());
        assert(f.size() == g.size());
        uli s = numeric_limits<uli>::max();
        for (ui i = 0; i < f.size(); ++i) s = min<uli>(s, f[i] + g[i]);
        ans += s;
        tag = true;
      } else {
        for (size_t j = 0; j < i.second.size(); j += 2)
          ans += (i.second[j + 1] - i.second[j]) / k;
      }
    }
    cout << ans << '\n';
  failed:;
  }
  return 0;
}