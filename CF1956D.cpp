#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned long long int;
using uli = unsigned long long int;
using li = long long int;
struct search_status {
  bool type;
  uli x;
  size_t p;
};
void f(vector<ui> const& a, size_t p, uli v, vector<search_status>& stk,
       size_t& maxval, vector<search_status>& ans) {
  if (p == a.size()) {
    if (v > maxval) maxval = v, ans = stk;
  } else {
    stk.push_back({0, a[p], p});
    f(a, p + 1, v + a[p], stk, maxval, ans);
    stk.back().type = 1;
    for (stk.back().x = 1; stk.back().x + p <= a.size(); ++stk.back().x)
      f(a, p + stk.back().x, v + stk.back().x * stk.back().x, stk, maxval, ans);
    stk.pop_back();
  }
}
template <typename Iterator>
void g(vector<ui> const& a, size_t p, size_t n, Iterator it) {
  if (n == 0) return;
  *it++ = {p, p + 1};
  for (size_t i = 1; i <= n; ++i) {
    g(p + 1, n - 1, it);
    *it++ = {p, p + 1};
  }
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  size_t maxval = 0;
  vector<search_status> ans, stk;
  f(a, 0, 0, stk, maxval, ans);
  vector<pair<size_t, size_t>> output;
  auto it = back_inserter(output);
  uli sum = 0;
  for (search_status i : ans) {
    if (i.type) g(a, i.p, i.x, it);
    sum += i.type ? i.x * i.x : i.x;
  }
  cout << sum << ' ' << output.size() << '\n';
  for (auto i : output) cout << i.first + 1 << ' ' << i.second << '\n';
  return 0;
}