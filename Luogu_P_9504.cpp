#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using node = pair<ui, size_t>;
using graph = vector<vector<pair<size_t, ui>>>;
namespace readns {
char buf[1 << 20], *_now = buf, *_end = buf;
// buf是缓冲数组，就是读入的一串数据存放的地方；_now是字符指针，指向当前想取的那个字符；_end也是字符指针，指向这一串字符的最后一个。
inline char getch() {
  if (_now == _end) {  // 如果这一串数据处理完了
    _end = _now = buf;
    _end += fread(buf, 1, 1 << 20, stdin);  // 那就再读一串，注意指针要回归原位
    if (_now == _end) {  // 如果没有读进来，就说明没有数据了
      return EOF;
    }
  }
  return *_now++;
}
template <typename type> inline void read(type& x) {
  x = 0;
  bool flag(0);
  char ch = getchar();
  while (!isdigit(ch)) flag = ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  flag ? x = -x : 0;
}
}  // namespace readns
void spfa(graph const& mp, vector<ui>& dis, size_t p) {
  vector<bool> vis(mp.size());
  deque<size_t> q({p});
  dis[p] = 0;
  vis[p] = 1;
  while (!q.empty()) {
    size_t u = q.front();
    q.pop_front();
    vis[u] = false;
    for (pair<size_t, ui> const& i : mp[u]) {
      if (dis[i.first] > dis[u] + i.second) {
        dis[i.first] = dis[u] + i.second;
        if (!vis[i.first]) {
          if (!q.empty() && dis[i.first] > dis[q.front()]) {
            q.push_back(i.first);
          } else
            q.push_front(i.first);
          vis[i.first] = true;
        }
      }
    }
  }
}
struct edge {
  size_t u, v;
  ui w;
};
int main(void) {
  size_t n, m, s, t;
  readns::read(n), readns::read(m), readns::read(s), readns::read(t);
  --s, --t;
  vector<edge> tmp(m);
  ui maxw = 0;
  for (edge& i : tmp)
    readns::read(i.u), readns::read(i.v), readns::read(i.w), --i.u, --i.v,
        maxw = max(maxw, i.w);
  graph mp(n * (maxw + 2));
  for (edge const& i : tmp) {
    size_t const &x = i.u, &y = i.v;
    ui const& w = i.w;
    for (size_t i = 0; i <= maxw; i++)
      mp[x + i * n].push_back({y + i * n + n, w / (i + 1)}),
          mp[y + i * n].push_back({x + i * n + n, w / (i + 1)});
    mp[x + (maxw + 1) * n].push_back({y + (maxw + 1) * n, w / (maxw + 1)}),
        mp[y + (maxw + 1) * n].push_back({x + (maxw + 1) * n, w / (maxw + 1)});
  }
  for (size_t i = 0; i <= maxw; i++)
    mp[s + i * n].push_back({s + i * n + n, 0});
#ifdef debug
  for (size_t i = 0; i < mp.size(); i++) {
    cout << i << ':';
    for (pair<size_t, ui> const& j : mp[i])
      cout << j.first << ',' << j.second << ' ';
    cout << '\n';
  }
#endif
  vector<ui> dis(n * (maxw + 2), 0x7fffffff);
  spfa(mp, dis, t);
  cout << dis[s + n * (maxw + 1)];
  return 0;
}