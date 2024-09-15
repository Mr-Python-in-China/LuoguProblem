#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct pos {
  double x, y;
  static constexpr double dist(pos const& a, pos const& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
  }
  friend istream& operator>>(istream& in, pos& p) { return in >> p.x >> p.y; }
};
pos constexpr o = {0, 0};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  cout << fixed << setprecision(10);
  while (T--) {
    pos p, a, b;
    cin >> p >> a >> b;
    cout << min({
                max(pos::dist(a, o), pos::dist(a, p)),
                max(pos::dist(b, o), pos::dist(b, p)),
                max({pos::dist(a, o), pos::dist(b, p), pos::dist(a, b) / 2}),
                max({pos::dist(a, p), pos::dist(b, o), pos::dist(a, b) / 2}),
            })
         << '\n';
  }
  return 0;
}