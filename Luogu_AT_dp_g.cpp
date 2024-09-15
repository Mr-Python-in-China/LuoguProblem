#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<vector<size_t>> mp(n);
  vector<size_t> inc(n);
  while (m--) {
    size_t x, y;
    cin >> x >> y;
    mp[--x].emplace_back(--y);
    ++inc[y];
  }
  queue<size_t> q;
  vector<size_t> f(n);
  for (size_t i = 0; i < n; ++i)
    if (!inc[i]) q.emplace(i);
  while (!q.empty()) {
    size_t p = q.front();
    q.pop();
    for (size_t i : mp[p]) {
      f[i] = max(f[i], f[p] + 1);
      if (!--inc[i]) q.push(i);
    }
  }
  cout << *max_element(f.begin(), f.end());
  return 0;
}