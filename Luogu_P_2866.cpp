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
  size_t ans = 0;
  stack<ui> stk;
  for (size_t i = 0; i < n; ++i) {
    ui x;
    cin >> x;
    while (!stk.empty() && stk.top() <= x) stk.pop();
    ans += stk.size();
    stk.push(x);
  }
  cout << ans;
  return 0;
}