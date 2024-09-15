#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned long long int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, m, k, d;
    cin >> n >> m >> k >> d;
    ++d;
    vector<ui> ans(n);
    for (ui& sum : ans) {
      vector<ui> a(m);
      for (ui& i : a) cin >> i, ++i;
      vector<ui> f(m);
      f[0] = a[0];
      deque<size_t> q({0});
      for (size_t i = 1; i < m; ++i) {
        f[i] = f[q.front()] + a[i];
        if (q.front() + d <= i) q.pop_front();
        while (!q.empty() && f[q.back()] > f[i]) q.pop_back();
        q.push_back(i);
      }
      sum = f.back();
    }
    ui s = numeric_limits<ui>::max();
    for (vector<ui>::const_iterator it = ans.cbegin(), jt = it + k;
         jt <= ans.cend(); ++it, ++jt)
      s = min(s, accumulate(it, jt, uli(0)));
    cout << s << '\n';
  }
  return 0;
}