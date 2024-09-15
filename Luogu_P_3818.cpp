#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using uc = unsigned char;
using li = long long int;
struct people {
  li x, y;
  uc shifted = 0;
  inline friend istream& operator>>(istream& in, people& p) {
    return in >> p.x >> p.y;
  }
  inline friend ostream& operator<<(ostream& out, const people& p) {
    return out << p.x + 1 << ',' << p.y + 1 << ':' << ui(p.shifted);
  }
  enum class op : uc { Left, Right, Up, Down };
  people(const people& from, const op& opt) {
    *this = from;
    switch (opt) {
      case op::Left: y--; break;
      case op::Right: y++; break;
      case op::Up: x--; break;
      case op::Down: x++; break;
    }
  }
  people(const li& _x, const li& _y): x(_x), y(_y) {}
  people() = default;
  friend inline bool operator==(const people& a, const people& b) {
    return a.x == b.x && a.y == b.y && a.shifted == b.shifted;
  }
};
namespace std {
template <> struct hash<people>: public __hash_base<li, people> {
  inline li operator()(people __val) const noexcept {
    return ((hash<li>()(__val.x) << 18) + (hash<li>()(__val.y) << 2) +
            __val.shifted);
  }
};
}  // namespace std
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  li h, w, d, r;
  cin >> h >> w >> d >> r;
  vector<vector<bool>> mp(h, vector<bool>(w));
  for (vector<vector<bool>>::reference i : mp)
    for (vector<bool>::reference j : i) {
      char c;
      cin >> c;
      j = c == '.';
    }
  unordered_map<people, li> vis;
  vis[people(0, 0)] = 0;
  queue<people> q({people(0, 0)});
  while (!q.empty()) {
    people p = q.front();
    q.pop();
    // cout<<p<<":\n";
    if (p.x == h - 1 && p.y == w - 1) cout << vis[p], exit(0);
    for (people::op i = people::op::Left; i <= people::op::Down;
         i = people::op(uc(i) + 1)) {
      people np(p, i);
      if (np.x >= 0 && np.y >= 0 && np.x < h && np.y < w && mp[np.x][np.y] &&
          !vis.count(np))
        vis[np] = vis[p] + 1, q.push(np) /*,cout<<uc(i)+1<<"->"<<np<<'\n'*/;
    }
    if (p.shifted == 0) {
      people np(p);
      np.x += d, np.y += r, np.shifted = 1;
      if (np.x >= 0 && np.y >= 0 && np.x < h && np.y < w && mp[np.x][np.y] &&
          !vis.count(np))
        vis[np] = vis[p] + 1, q.push(np) /*,cout<<"5->"<<np<<'\n'*/;
    }
  }
  cout << "-1";
  return 0;
}
