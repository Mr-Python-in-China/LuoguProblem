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
    uli x;
    cin >> n >> x;
    vector<uli> a(n);
    for (uli& i : a) cin >> i;
    uli l = 1, r = 2e9;
    while (l < r) {
      uli mid = (l + r + 1) >> 1, water = 0;
      for (uli const& i : a)
        if (i < mid) water += mid - i;
      water > x ? r = mid - 1 : l = mid;
    }
    cout << l << '\n';
  }
  return 0;
}