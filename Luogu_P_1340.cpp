#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
struct dsds {
  vector<size_t> fa;
  dsds(const size_t& n) {
    fa.resize(n);
    for (size_t i = 0; i < n; i++) fa[i] = i;
  }
  inline size_t find(const size_t& n) {
    return fa[n] == n ? n : fa[n] = find(fa[n]);
  }
  inline void link(const size_t& a, const size_t& b) { fa[find(a)] = find(b); }
  inline bool in_one_set(const size_t& a, const size_t& b) {
    return find(a) == find(b);
  }
};
struct edge {
  size_t u, v;
  ui w;
  friend inline istream& operator>>(istream& in, edge& e) {
    return in >> e.u >> e.v >> e.w;
  }
  friend inline bool operator<(const edge& a, const edge& b) {
    return a.w < b.w;
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, w;
  cin >> n >> w;
  multiset<edge> st;
  while (w--) {
    edge e;
    cin >> e;
    e.u--, e.v--;
    st.insert(e);
    size_t cnt = 0, ans = 0;
    dsds dst(n);
    for (set<edge>::const_reference i : st)
      if (!dst.in_one_set(i.u, i.v)) {
        dst.link(i.u, i.v);
        ans += i.w;
        if (++cnt >= n - 1) break;
      }
    cout << (cnt >= n - 1 ? int(ans) : -1) << '\n';
  }
  return 0;
}