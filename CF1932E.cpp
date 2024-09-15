#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using uc = unsigned char;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<ui> s(n);
    for (ui& i : s) {
      char c;
      cin >> c;
      i = c - '0';
    }
    vector<uli> ans(n);
    partial_sum(s.cbegin(), s.cend(), ans.begin());
    for (size_t i = n - 1; i > 0; --i) ans[i - 1] += ans[i] / 10, ans[i] %= 10;
    vector<uli>::const_iterator it = ans.begin();
    while (it < ans.end() && *it == 0) ++it;
    if (it == ans.end())
      cout.put('0');
    else
      for (; it < ans.end(); ++it) cout << *it;
    cout.put('\n');
  }
  return 0;
}