#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using graph = vector<vector<size_t>>;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  graph mp1(n), mp2(n);
  vector<ui> deg_in(n);
  while (m--) {
    size_t x, y;
    cin >> x >> y;
    --x, --y;
    mp1[x].push_back(y), mp2[y].push_back(x);
    deg_in[y]++;
  }
  vector<size_t> tpsort;
  tpsort.reserve(n);
  queue<size_t> q;
  for (ui i = 0; i < n; i++)
    if (!deg_in[i]) q.push(i);
  while (!q.empty()) {
    ui p = q.front();
    q.pop();
    tpsort.push_back(p);
    for (vector<size_t>::reference i : mp1[p])
      if (!--deg_in[i]) q.push(i);
  }
  vector<ui> dp(n, 1);
  for (vector<size_t>::reference np : tpsort)
    for (vector<size_t>::reference i : mp2[np]) dp[np] = max(dp[np], dp[i] + 1);
  for (vector<ui>::reference i : dp) cout << i << '\n';
  return 0;
}