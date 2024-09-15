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
  vector<ui> a(n), b(n);
  for (ui &i : a) cin >> i;
  for (ui &i : b) cin >> i;
  uli v = 0;
  auto cmp = [&b](size_t x, size_t y) { return b[x] < b[y]; };
  priority_queue<size_t, vector<size_t>, decltype(cmp)> q(cmp);
  for (size_t i = 0; i < n; ++i) {
    v += a[i];
    if (v >= b[i])
      v -= b[i], q.push(i);
    else if (!q.empty()) {
      size_t p = q.top();
      if (b[p] > b[i]) (v += b[p]) -= b[i], q.pop(), q.push(i);
    }
  }
  cout << q.size() << '\n';
  vector<size_t> ans;
  while (!q.empty()) ans.emplace_back(q.top()), q.pop();
  sort(ans.begin(), ans.end());
  for (size_t i : ans) cout << i + 1 << ' ';
  return 0;
}