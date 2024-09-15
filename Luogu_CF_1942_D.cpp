#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T, typename C, typename F = less<T>>
void insert_sorted(T const &val, C &c, F const &f = F()) {
  c.insert(lower_bound(c.begin(), c.end(), val, f), val);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, k;
    cin >> n >> k;
    vector<vector<int>> d(n);
    for (size_t i = 0; i < n; ++i) {
      d[i].resize(n - i);
      for (int &j : d[i]) cin >> j;
    }
    vector<vector<int>> f(n);
    k == 1 ? f[0] = {max(0, d[0][0])}
           : f[0] = {max(0, d[0][0]), min(0, d[0][0])};
    for (size_t i = 1; i < n; ++i) {
      f[i] = f[i - 1];
      insert_sorted(d[0][i], f[i], greater<int>()),
          insert_sorted(d[1][i - 1], f[i], greater<int>());
      size_t mid = f[i].size();
      priority_queue<pair<int, size_t>> q;
      vector<size_t> head;
      for (size_t j = 0; j + 1 < i; ++j)
        q.emplace(f[j][0] + d[j + 2][i - (j + 2)], j), head.emplace_back(0);
      for (size_t j = 0; j < k && !q.empty(); ++j) {
        auto p = q.top();
        q.pop();
        f[i].emplace_back(p.first);
        if (++head[p.second] < f[p.second].size())
          q.emplace(p.first - f[p.second][head[p.second] - 1] +
                        f[p.second][head[p.second]],
                    p.second);
      }
      inplace_merge(f[i].begin(), f[i].begin() + mid, f[i].end(),
                    greater<int>());
      if (f[i].size() > k) f[i].resize(k);
    }
    for (int i : f.back()) cout << i << ' ';
    cout << '\n';
  }
  return 0;
}