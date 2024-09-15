#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename a, typename b> auto mymod(a x, b y) { return x % y; }
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli n;
  string s, t;
  cin >> n >> s >> t;
  array<vector<size_t>, 26> bt = {};
  for (size_t i = 0; i < s.size(); ++i) bt[s[i] - 'a'].push_back(i);
  uli l = 0, r = 1e18;
  auto f = [&](uli mid) {
    uli p = 0;
    for (char i : t) {
      if (bt[i - 'a'].empty()) return false;
      size_t d =
          lower_bound(bt[i - 'a'].cbegin(), bt[i - 'a'].cend(), p % s.size()) -
          bt[i - 'a'].cbegin();
      uli u = p % s.size(), v = bt[i - 'a'][(d + mid - 1) % bt[i - 'a'].size()];
      uli turn = (mid - 1) / bt[i - 'a'].size();
      p += turn * s.size() + (v + s.size() * (u > v) - u) + 1;
      if (p > s.size() * n) return false;
    }
    return true;
  };
  while (l < r) {
    size_t mid = (l + r + 1) / 2;
    f(mid) ? l = mid : r = mid - 1;
  }
  cout << l;
  return 0;
}