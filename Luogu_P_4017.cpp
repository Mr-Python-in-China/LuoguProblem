#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using graph = vector<vector<ui>>;
const ui P = 80112002;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n, m;
  cin >> n >> m;
  graph mp(n), rmp(n);
  vector<ui> in(n), out(n);
  while (m--) {
    ui a, b;
    cin >> a >> b;
    --a, --b;
    mp[a].push_back(b), rmp[b].push_back(a);
    in[b]++, out[a]++;
  }
  vector<ui> ans(n);
  queue<ui> q;
  for (ui i = 0; i < n; i++)
    if (!in[i]) ans[i] = 1, q.push(i);
  while (!q.empty()) {
    ui p = q.front();
    q.pop();
    for (vector<ui>::reference i : rmp[p]) ans[p] = (ans[p] + ans[i]) % P;
    for (vector<ui>::reference i : mp[p])
      if (!--in[i]) q.push(i);
  }
  ui res = 0;
  for (ui i = 0; i < n; i++)
    if (!out[i]) res = (res + ans[i]) % P;
  cout << res;
  return 0;
}