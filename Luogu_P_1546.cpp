#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
struct edge {
  ui u, v, w;
  bool friend operator<(const edge a, const edge b) { return a.w < b.w; }
};
inline ui find(vector<ui>& fa, const ui x) {
  return fa[x] == x ? x : fa[x] = find(fa, fa[x]);
}
inline void link(vector<ui>& fa, const ui x, const ui y) {
  fa[find(fa, x)] = find(fa, y);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n;
  cin >> n;
  vector<edge> e;
  for (ui i = 0; i < n; i++)
    for (ui j = 0; j < n; j++) {
      ui x;
      cin >> x;
      if (j < i) e.push_back({i, j, x});
    }
  sort(e.begin(), e.end());
  ui ans = 0, tot = 1;
  vector<ui> fa(n);
  for (ui i = 0; i < n; i++) fa[i] = i;
  for (vector<edge>::reference i : e)
    if (find(fa, i.u) != find(fa, i.v)) {
      link(fa, i.u, i.v);
      ans += i.w, tot++;
      if (tot >= n) break;
    }
  cout << ans;
  return 0;
}