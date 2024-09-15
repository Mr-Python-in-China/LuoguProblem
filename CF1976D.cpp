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
    string s;
    cin >> s;
    vector<int> c = {0};
    for (char i : s) c.emplace_back(c.back() + (i == ')' ? -1 : 1));
    vector<size_t> stk;
    map<int, vector<size_t>> r;
    uli ans = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      size_t d = stk.rend() -
                 upper_bound(stk.rbegin(), stk.rend(), c[i] * 2,
                             [&c](int x, size_t p) { return x < c[p]; }) -
                 1;
      size_t p = (!~d ? 0 : stk[d] + 1);
      vector<size_t>& target = r[c[i]];
      ans += target.end() - lower_bound(target.begin(), target.end(), p);
      target.emplace_back(i);

      while (!stk.empty() && c[stk.back()] <= c[i]) stk.pop_back();
      stk.push_back(i);
    }
    cout << ans << '\n';
  }
  return 0;
}