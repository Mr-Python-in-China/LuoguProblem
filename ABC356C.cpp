#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, k;
  cin >> n >> m >> k;
  vector<pair<ui, bool>> s(m);
  for (auto &i : s) {
    size_t c;
    cin >> c;
    for (size_t j = 0; j < c; ++j) {
      size_t p;
      cin >> p;
      --p;
      i.first |= (1 << p);
    }
    char r;
    cin >> r;
    i.second = r == 'o';
  }
  size_t ans = 0;
  for (ui status = 0; status < (1 << n); ++status) {
    for (auto const &j : s)
      if ((__builtin_popcount(status & j.first) >= k) != j.second) goto failed;
    ++ans;
  failed:;
  }
  cout << ans;
  return 0;
}