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
    cin >> n;
    vector<ui> a(n);
    ui mina = numeric_limits<ui>::max(), maxa = numeric_limits<ui>::min();
    for (ui& i : a) cin >> i, mina = min(mina, i), maxa = max(maxa, i);
    vector<bool> ans;
    while (maxa - mina > 1) {
      mina = numeric_limits<ui>::max(), maxa = numeric_limits<ui>::min();
      for (ui& i : a) i >>= 1, mina = min(mina, i), maxa = max(maxa, i);
      ans.push_back(false);
    }
    if (maxa - mina == 1) ans.push_back(mina & 1);
    cout << ans.size() << '\n';
    if (ans.size() <= n && ans.size()) {
      for (vector<bool>::reference i : ans) cout << i << ' ';
      cout << '\n';
    }
  }
  return 0;
}