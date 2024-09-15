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
  vector<ui> sorted;
  size_t ans = 1;
  for (size_t i = 0; i < n; ++i) {
    ui x;
    cin >> x;
    vector<ui>::iterator p =
        lower_bound(sorted.begin(), sorted.end(), x, greater<ui>());
    ans = max<size_t>(ans, p - sorted.begin());
    sorted.insert(p, x);
  }
  cout << ans;
  return 0;
}