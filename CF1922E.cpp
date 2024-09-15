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
    uli x;
    cin >> x;
    vector<int> ans;
    uli nx = x ^ (1 << (sizeof(uli) * 8 - __builtin_clzll(x) - 1));
    for (int i = 0; x > 1; ++i, x >>= 1) {
      if (x & 1) ans.push_back(114514);
      ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (int const& i : ans) cout << i << ' ';
    cout.put('\n');
  }
  return 0;
}