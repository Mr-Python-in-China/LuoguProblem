#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
struct pos {
  ui x, y;
  friend istream& operator>>(istream& in, pos& p) { return in >> p.x >> p.y; }
  struct hash {
    size_t operator()(pos const& p) const {
      return (size_t(p.x) << (1 << (sizeof(size_t) >> 1))) + p.y;
    }
  };
  friend bool operator==(pos const& x, pos const& y) {
    return x.x == y.x && x.y == y.y;
  }
  pos& operator+=(pos const& p) {
    x += p.x, y += p.y;
    return *this;
  }
  friend pos operator+(pos x, pos y) { return x += y; }
  static pos const f[24];
};
pos constexpr pos::f[24] = {
    {ui(-2), ui(-2)},
    {ui(-2), ui(-1)},
    {ui(-2),  ui(0)},
    {ui(-2), ui(+1)},
    {ui(-2), ui(+2)},
    {ui(-1), ui(-2)},
    {ui(-1), ui(-1)},
    {ui(-1),  ui(0)},
    {ui(-1), ui(+1)},
    {ui(-1), ui(+2)},
    { ui(0), ui(-2)},
    { ui(0), ui(-1)},
    { ui(0), ui(+1)},
    { ui(0), ui(+2)},
    {ui(+1), ui(-2)},
    {ui(+1), ui(-1)},
    {ui(+1),  ui(0)},
    {ui(+1), ui(+1)},
    {ui(+1), ui(+2)},
    {ui(+2), ui(-2)},
    {ui(+2), ui(-1)},
    {ui(+2),  ui(0)},
    {ui(+2), ui(+1)},
    {ui(+2), ui(+2)}
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui t;
  cin >> n >> t;
  unordered_set<pos, pos::hash> a;
  unordered_set<pos, pos::hash> vis({
      {0, 0}
  });
  for (size_t i = 0; i < n; i++) {
    pos x;
    cin >> x;
    a.insert(x);
  }
  queue<pos> q({
      {0, 0}
  });
  size_t ans = 0;
  while (!q.empty()) {
    for (size_t _ = q.size(); _ > 0; _--) {
      pos p = q.front();
      q.pop();
      if (p.y >= t) return cout << ans, 0;
      for (pos const& i : pos::f) {
        pos np = p + i;
        if (np.x <= 1000000 && np.y <= t && a.count(np) && !vis.count(np))
          vis.insert(np), q.push(np);
      }
    }
    ans++;
  }
  return cout << "-1", 0;
}