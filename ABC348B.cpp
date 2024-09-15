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
  vector<pair<int, int>> a(n);
  for (pair<int, int>& i : a) cin >> i.first >> i.second;
  for (pair<int, int> const& i : a) {
    size_t p = 0;
    for (size_t j = 1; j < n; ++j)
      if ((i.first - a[p].first) * (i.first - a[p].first) +
              (i.second - a[p].second) * (i.second - a[p].second) <
          (i.first - a[j].first) * (i.first - a[j].first) +
              (i.second - a[j].second) * (i.second - a[j].second))
        p = j;
    cout << p + 1 << '\n';
  }
  return 0;
}