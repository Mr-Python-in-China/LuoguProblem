#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr ui P = 1e9 + 7;
using graph = vector<vector<size_t>>;
pair<ui, ui> f(size_t p, size_t fa, graph const &mp) {
  uli x = 1, y = 1;
  for (size_t i : mp[p])
    if (i != fa) {
      auto res = f(i, p, mp);
      (x *= res.second) %= P;
      (y *= res.first + res.second) %= P;
    }
  return {x, y};
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  fin >> n;
  graph mp(n);
  for (size_t i = 1; i < n; ++i) {
    size_t x, y;
    fin >> x >> y;
    --x, --y;
    mp[x].emplace_back(y), mp[y].emplace_back(x);
  }
  auto res = f(0, ~0, mp);
  cout << (res.first + res.second) % P;
  return 0;
}