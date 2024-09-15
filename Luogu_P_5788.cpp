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
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  vector<size_t> ans;
  stack<size_t> stk;
  for (size_t i = n - 1; i < n; --i) {
    while (!stk.empty() && a[stk.top()] <= a[i]) stk.pop();
    ans.push_back(stk.empty() ? -1 : stk.top());
    stk.push(i);
  }
  for_each(ans.crbegin(), ans.crend(), [&](size_t x) { cout << x + 1 << ' '; });
  return 0;
}