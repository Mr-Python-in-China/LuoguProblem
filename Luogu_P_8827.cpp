#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using graph = vector<unordered_set<size_t>>;
struct edge {
  size_t u = -1, v = -1;
  bool removed = false;
  inline friend istream& operator>>(istream& in, edge& x) {
    return in >> x.u >> x.v;
  }
};
struct dsds {
  vector<size_t> fa;
  dsds(size_t n) {
    fa.resize(n);
    for (size_t i = 0; i < n; i++) fa[i] = i;
  }
  inline size_t find(size_t x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  inline bool in_one_set(size_t a, size_t b) { return find(a) == find(b); }
  inline void link(size_t a, size_t b) { fa[find(a)] = find(b); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<ui> val(n);
  for (vector<ui>::reference i : val) cin >> i;
  vector<edge> e(n - 1);
  for (vector<edge>::reference i : e) cin >> i, --i.u, --i.v;
  vector<pair<char, size_t>> op(m);
  vector<size_t> op1, op3;
  vector<pair<size_t, ui>> op2;
  for (vector<pair<char, size_t>>::reference i : op) {
    cin >> i.first, i.first -= '0';
    switch (i.first) {
      case 1: {
        size_t e;
        cin >> e;
        i.second = op1.size();
        op1.push_back(--e);
        break;
      }
      case 2: {
        size_t u;
        ui val;
        cin >> u >> val;
        i.second = op2.size();
        op2.push_back({--u, val});
        break;
      }
      case 3: {
        size_t u;
        cin >> u;
        i.second = op3.size();
        op3.push_back(--u);
        break;
      }
    }
  }
  vector<ui> ans(op3.size());
  for (vector<size_t>::reference i : op1) e[i].removed = true;
  for (vector<pair<size_t, ui>>::reference i : op2)
    swap(val[i.first], i.second);
  dsds ds(n);
  for (vector<edge>::reference i : e)
    if (!i.removed) ds.link(i.u, i.v);
  vector<ui> tree_val(n);
  for (size_t i = 0; i < n; i++) tree_val[ds.find(i)] += val[i];
  for (vector<pair<char, size_t>>::const_reverse_iterator i = op.crbegin();
       i != op.crend(); i++) {
    switch (i->first) {
      case 1: {
        const size_t &x = e[op1[i->second]].u, &y = e[op1[i->second]].v;
        if (!ds.in_one_set(x, y))
          tree_val[ds.find(y)] += tree_val[ds.find(x)], ds.link(x, y);
        break;
      }
      case 2: {
        const size_t &u = op2[i->second].first, &v = op2[i->second].second;
        tree_val[ds.find(u)] -= val[u], tree_val[ds.find(u)] += (val[u] = v);
        break;
      }
      case 3: {
        const size_t& u = op3[i->second];
        ans[i->second] = tree_val[ds.find(u)];
        break;
      }
    }
  }
  for (vector<ui>::const_reference i : ans) cout << i << '\n';
  return 0;
}