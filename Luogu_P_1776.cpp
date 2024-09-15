#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui t;
  cin >> n >> t;
  vector<ui> f(t + 1);
  while (n--) {
    ui v, w, m;
    cin >> v >> w >> m;
    vector<ui> g(t + 1);
    vector<deque<size_t>> qs(w);
    for (ui i = 0; i * w <= t; ++i)
      for (ui j = 0; j < w && i * w + j <= t; ++j) {
        deque<size_t>& q = qs[j];
        auto gv = [i, j, v, w, &f](size_t p) {
          return f[p * w + j] + (i - p) * v;
        };
        if (i >= m)
          if (q.front() < i - m) q.pop_front();
        g[i * w + j] = q.empty() ? 0 : gv(q.front());
        while (!q.empty() && gv(q.back()) <= gv(i)) q.pop_back();
        q.push_back(i);
      }
    for (size_t i = 0; i <= t; ++i) f[i] = max(f[i], g[i]);
  }
  cout << f.back();
  return 0;
}