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
    priority_queue<ui> t;
    priority_queue<ui, vector<ui>, greater<ui>> s;
    s.push(numeric_limits<ui>::max()), t.push(numeric_limits<ui>::min());
    vector<ui> ans;
    for (size_t i = 0; i < n; ++i) {
      ui x;
      cin >> x;
      s.push(x);
      if (s.size() - 1 > t.size()) t.push(s.top()), s.pop();
      if (s.top() < t.top()) {
        ui x = s.top(), y = t.top();
        s.pop(), t.pop();
        s.push(y), t.push(x);
      }
      if (i % 2 == 0 && (ans.empty() || s.top() != ans.back()))
        ans.push_back(s.top());
    }
    cout << ans.size() << '\n';
    for (ui i : ans) cout << i << ' ';
    cout << '\n';
  }
  return 0;
}