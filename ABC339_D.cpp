#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
using uc = unsigned char;
struct pos {
  uc x, y;
  friend bool operator==(pos x, pos y) { return x.x == y.x && x.y == y.y; }
};
struct myhash {
  size_t operator()(pair<pos, pos> p) const {
    return (p.first.x << 24) | (p.first.y << 16) | (p.second.x << 8) |
           (p.second.y << 0);
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<vector<bool>> mp(n + 2, vector<bool>(n + 2));
  for (size_t i = 0; i < n + 2; ++i)
    mp[0][i] = mp[i][0] = mp[n + 1][i] = mp[i][n + 1] = '.';
  pos p1 = {255U, 255U}, p2 = {255U, 255U};
  for (uc i = 1; i <= n; ++i)
    for (uc j = 1; j <= n; ++j) {
      char c;
      cin >> c;
      mp[i][j] = c == '#';
      if (c == 'P') (p1.x == 255U && p2.x == 255U ? p1 : p2) = {i, j};
    }
  queue<pair<pos, pos>> q;
  q.emplace(p1, p2);
  unordered_set<pair<pos, pos>, myhash> vis;
  vis.emplace(p1, p2);
  size_t c = 0;
  while (!q.empty()) {
    for (size_t _ = q.size(); _ > 0; --_) {
      pair<pos, pos> p = q.front();
      q.pop();
      if (p.first == p.second) return cout << c, 0;
      for (uc i = 0; i < 4; ++i) {
        pair<pos, pos> np = {
            { p.first.x + uc(i == 0   ? 1
 : i == 1 ? 0
 : i == 2 ? -1
 : i == 3 ? 0
 : throw),
             p.first.y + uc(i == 0   ? 0
             : i == 1 ? 1
             : i == 2 ? 0
             : i == 3 ? -1
             : throw)},
            {p.second.x + uc(i == 0   ? 1
: i == 1 ? 0
: i == 2 ? -1
: i == 3 ? 0
: throw),
             p.second.y + uc(i == 0   ? 0
             : i == 1 ? 1
             : i == 2 ? 0
             : i == 3 ? -1
             : throw)}
        };
        if (mp[np.first.x][np.first.y]) np.first = p.first;
        if (mp[np.second.x][np.second.y]) np.second = p.second;
        if (!vis.count(np)) vis.insert(np), q.push(np);
      }
    }
    ++c;
  }
  cout << "-1";
  return 0;
}