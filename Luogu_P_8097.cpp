#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct Operator {
  char type;
  union {
    size_t d;
    pair<size_t, size_t> r;
    pair<size_t, size_t> a;
  } val;
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  fin >> n >> m;
  vector<unordered_set<size_t>> mp(n);
  vector<Operator> op;
  vector<pair<size_t, size_t>> e;
  vector<bool> flag(n, true);
  for (size_t i = 0; i < m; ++i) {
    char c;
    fin >> c;
    op.push_back({c});
    if (c == 'D') {
      fin >> op.back().val.d;
      flag[--op.back().val.d] = false;
    } else if (c == 'A') {
      e.emplace_back();
      fin >> e.back().first >> e.back().second;
      --e.back().first, --e.back().second;
      op.back().val.a = e.back();
      mp[op.back().val.a.first].emplace(op.back().val.a.second);
      mp[op.back().val.a.second].emplace(op.back().val.a.first);
    } else if (c == 'R') {
      size_t x;
      fin >> x;
      op.back().val.r = e[--x];
      mp[op.back().val.r.first].erase(op.back().val.r.second);
      mp[op.back().val.r.second].erase(op.back().val.r.first);
    }
  }
  vector<size_t> ans(n, ~0);
  auto bfs = [&](size_t s, size_t t) {
    if (~ans[s]) return;
    ans[s] = t;
    queue<size_t> q({s});
    while (!q.empty()) {
      size_t p = q.front();
      q.pop();
      for (size_t i : mp[p])
        if (!~ans[i]) ans[i] = t, q.emplace(i);
    }
  };
  for (size_t i = 0; i < n; ++i)
    if (flag[i]) bfs(i, m);
  for (size_t t = m - 1; t < m; --t) {
    if (op[t].type == 'D')
      bfs(op[t].val.d, t);
    else if (op[t].type == 'R') {
      mp[op[t].val.r.first].emplace(op[t].val.r.second);
      mp[op[t].val.r.second].emplace(op[t].val.r.first);
      if (~ans[op[t].val.r.first]) bfs(op[t].val.r.second, t);
      if (~ans[op[t].val.r.second]) bfs(op[t].val.r.first, t);
    }
  }
  for (size_t i : ans) fout << i << '\n';
  return 0;
}