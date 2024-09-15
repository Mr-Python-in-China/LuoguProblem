#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
struct pos: pair<int, int> {
  int &x = pair::first, &y = pair::second;
  inline friend istream& operator>>(istream& in, pos& a) {
    return in >> a.x >> a.y;
  }
};
struct edge {
  size_t u, v;
  ui w;
  inline static ui get_len(const vector<pos>& dot, size_t u, size_t v) {
    int &x1 = dot[u].x, x2 = dot[v].x, y1 = dot[u].y, y2 = dot[v].y;
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  }
  edge(const vector<pos>& dot, size_t _u, size_t _v)
      : u(_u), v(_v), w(get_len(dot, u, v)) {}
  edge() = default;
  inline friend bool operator<(const edge& a, const edge& b) {
    return a.w < b.w;
  }
  inline bool operator<(const unsigned long long int& x) const { return w < x; }
};
class dsds {
  vector<size_t> fa;

 public:
  dsds(size_t n) {
    fa.resize(n);
    for (size_t i = 0; i < n; i++) fa[i] = i;
  }
  inline size_t find(size_t x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  inline bool in_one_set(size_t x, size_t y) { return find(x) == find(y); }
  inline void link(size_t x, size_t y) { fa[find(x)] = find(y); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, c;
  cin >> n >> c;
  vector<pos> a(n);
  vector<edge> e;
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
    for (size_t j = 0; j < i; j++)
      if (edge::get_len(a, j, i) >= c) e.push_back(edge(a, j, i));
  }
  sort(e.begin(), e.end());
  dsds ds(n);
  ui ans = 0;
  size_t cnt = 0;
  for (vector<edge>::iterator it = e.begin(); it != e.end(); it++)
    if (!ds.in_one_set(it->u, it->v)) {
      ds.link(it->u, it->v);
      ans += it->w, cnt++;
      if (cnt >= n - 1) cout << ans, exit(0);
    }
  cout << "-1";
  return 0;
}