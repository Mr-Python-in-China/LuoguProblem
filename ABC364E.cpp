#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui x, y;
  cin >> n >> x >> y;
  map<usi, map<usi, unsigned char>> f;
  f[0][0] = 0;
  while (n--) {
    usi u, v;
    cin >> u >> v;
    for_each(
        decltype(f)::reverse_iterator(f.upper_bound(x)), f.rend(),
        [&](decltype(f)::reference g) {
          for_each(
              decltype(g.second)::reverse_iterator(g.second.upper_bound(y)),
              g.second.rend(), [&](decltype(g.second)::reference h) {
                unsigned char &t =
                    f[g.first + u].emplace(h.first + v, 0).first->second;
                t = max<unsigned char>(t, h.second + 1);
              });
        });
  }
  unsigned char ans = 0;
  for (auto const &i : f)
    for (auto const &j : i.second) ans = max(ans, j.second);
  cout << ui(ans);
  return 0;
}