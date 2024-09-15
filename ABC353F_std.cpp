#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
long K;
vector<pair<pair<long, long>, long> > f(long x, long y) {
  vector<pair<pair<long, long>, long> > ret;
  if ((x / K + y / K) % 2 == 1) {
    ret.push_back(make_pair(make_pair(x / K, y / K), 0L));
  } else {
    ret.push_back(make_pair(make_pair(x / K - 1, y / K), x % K + 1));
    ret.push_back(make_pair(make_pair(x / K + 1, y / K), K - x % K));
    ret.push_back(make_pair(make_pair(x / K, y / K - 1), y % K + 1));
    ret.push_back(make_pair(make_pair(x / K, y / K + 1), K - y % K));
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long Sx, Sy, Tx, Ty;
  cin >> K >> Sx >> Sy >> Tx >> Ty;
  Sx += K;
  Sy += K;
  Tx += K;
  Ty += K;
  long ans = abs(Sx - Tx) + abs(Sy - Ty);
  for (auto sp : f(Sx, Sy))
    for (auto tp : f(Tx, Ty)) {
      auto [sx, sy] = sp.first;
      auto [tx, ty] = tp.first;
      long now = sp.second + tp.second;
      long dx = abs(sx - tx), dy = abs(sy - ty);
      now += min(dx, dy) * 2;
      long rest = dx + dy - 2 * min(dx, dy);
      assert(rest % 2 == 0);
      if (K >= 3)
        now += rest * 2;
      else
        now += rest / 2 * 3;
      ans = min(ans, now);
    }
  cout << ans << endl;
}
