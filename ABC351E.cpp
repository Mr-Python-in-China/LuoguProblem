#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  uli ans = 0;
  array<vector<pair<int, int>>, 2> d;
  for (size_t i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    d[(x ^ y) & 1].emplace_back((x + y) >> 1, (x - y) >> 1);
  }
  for (vector<pair<int, int>> const& a : d) {
    array<vector<int>, 2> p;
    for (pair<int, int> const& i : a)
      p[0].emplace_back(i.first), p[1].emplace_back(i.second);
    sort(p[0].begin(), p[0].end()), sort(p[1].begin(), p[1].end());
    for (auto const& s : p) {
      long long int r = s.size() - 1;
      for (size_t i = s.size() - 1; ~i; --i, r -= 2) ans += s[i] * r;
    }
  }
  cout << ans;
  return 0;
}