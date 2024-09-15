#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using uc = unsigned char;
template <typename T> struct position {
  T x, y;
  position(void): x(0), y(0){};
  position(T _x, T _y): x(_x), y(_y){};
  inline position operator+=(const position p) {
    return x += p.x, y += p.y, *this;
  }
  inline position operator-=(const position p) {
    return x -= p.x, y -= p.y, *this;
  }
  inline friend position operator+(position x, const position y) {
    return x += y;
  }
  inline friend position operator-(position x, const position y) {
    return x -= y;
  }
  static const position<T> F[4];
};
template <typename T>
const position<T> position<T>::F[4] = {
    {T(-1),  T(0)},
    {    0, T(-1)},
    { T(1),  T(0)},
    { T(0),  T(1)}
};
struct solution {
  array<array<uc, 3>, 3> table;
  position<uc> zero_pos;
  solution(void): zero_pos(2, 2) {
    table[0][0] = 1, table[0][1] = 2, table[0][2] = 3, table[1][0] = 4,
    table[1][1] = 5, table[1][2] = 6, table[2][0] = 7, table[2][1] = 8,
    table[2][2] = 0;
  }
  solution(string s) {
    for (uc i = 0; i < 3; i++)
      for (uc j = 0; j < 3; j++) {
        table[i][j] = s[i * 3 + j] - '0';
        if (s[i * 3 + j] == '0') zero_pos = {i, j};
      }
  }
  inline bool move(uc f) {
    position<uc> new_pos = zero_pos + position<uc>::F[f];
    if (new_pos.x >= 3 || new_pos.y >= 3) return false;
    swap(table[zero_pos.x][zero_pos.y], table[new_pos.x][new_pos.y]);
    zero_pos = new_pos;
    return true;
  }
  friend inline bool operator==(const solution a, const solution b) {
    for (uc i = 0; i < 3; i++)
      for (uc j = 0; j < 3; j++)
        if (a.table[i][j] != b.table[i][j]) return false;
    return true;
  }
};
namespace std {
template <> struct hash<solution> {
  size_t operator()(const solution s) const {
    size_t res = 0;
    for (uc i = 0; i < 3; i++)
      for (uc j = 0; j < 3; j++) res += hash<uc>()(s.table[i][j]) << i * 3 + j;
    return res;
  }
};
}  // namespace std
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  const solution to("123804765");
  string s;
  cin >> s;
  queue<solution> q({s});
  unordered_set<solution> vis;
  vis.reserve(1e6);
  size_t ans = 0;
  while (!q.empty()) {
    // cout<<q.size()<<'\n';
    for (size_t t = q.size(); t > 0; t--) {
      solution s = q.front();
      q.pop();
      if (s == to) cout << ans, exit(0);
      for (uc i = 0; i < 4; i++) {
        solution ns = s;
        if (ns.move(i))
          if (!vis.count(ns)) vis.insert(ns), q.push(ns);
      }
    }
    ans++;
  }
  return 0;
}