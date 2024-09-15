#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using uc = unsigned char;
struct rgb {
  uc r, g, b;
  inline rgb(void): r(0), g(0), b(0) {}
  inline friend bool operator==(const rgb& a, const rgb& b) {
    return a.r == b.r && a.g == b.g && a.b == b.b;
  }
  inline friend bool operator!=(const rgb& a, const rgb& b) {
    return !(a == b);
  }
};
struct pos: pair<size_t, size_t> {
  using pair<size_t, size_t>::pair;
  size_t &x = first, &y = second;
};
namespace std {
template <> struct hash<pos> {
  inline size_t operator()(const pos& a) const {
    const hash<size_t> h;
    return (h(a.x) << 16) + (h(a.y) << 0);
  }
};
}  // namespace std
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, q;
  cin >> n >> m >> q;
  vector<vector<rgb>> mp(n, vector<rgb>(m));
  unordered_set<pos> unasf;
  while (q--) {
    size_t i, j;
    char t;
    ui c;
    cin >> i >> j >> t >> c;
    --i, --j;
    switch (t) {
      case '1': mp[i][j].r += c; break;
      case '2': mp[i][j].g += c; break;
      case '3': mp[i][j].b += c; break;
    }
    if (mp[i][j] != mp[i][m - 1 - j])
      unasf.insert({i, min(j, m - 1 - j)});
    else if (unasf.count({i, min(j, m - 1 - j)}))
      unasf.erase({i, min(j, m - 1 - j)});
    cout << (unasf.empty() ? "Yes\n" : "No\n");
  }
  return 0;
}