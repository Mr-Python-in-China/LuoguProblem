#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = unsigned long long int;
struct Pos {
  uli x, y;
};
template <typename T> T abs_minus(T x, T y) { return max(x, y) - min(x, y); }
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli k;
  uli sx, sy, tx, ty;
  cin >> k >> sx >> sy >> tx >> ty;
  if (k == 1)
    cout << abs_minus(sx, tx) + abs_minus(sy, ty);
  else {
    sx += 2 * k, sy += 2 * k, tx += 2 * k, ty += 2 * k;
    array<pair<Pos, uli>, 4> sp =
            ((sx / k) ^ (sy / k)) & 1
                ? array<pair<Pos, uli>, 4>{{{Pos{sx / k, sy / k}, 0}, {Pos{sx / k, sy / k}, 0}, {Pos{sx / k, sy / k}, 0}, {Pos{sx / k, sy / k}, 0}}}
                : array<pair<Pos, uli>, 4>{{{Pos{sx / k - 1, sy / k}, sx % k + 1}, {Pos{sx / k, sy / k - 1}, sy % k + 1}, {Pos{sx / k + 1, sy / k}, k - sx % k}, {Pos{sx / k, sy / k + 1}, k - sy % k}}};
    array<pair<Pos, uli>, 4> tp =
            ((tx / k) ^ (ty / k)) & 1
                ? array<pair<Pos, uli>, 4>{{{Pos{tx / k, ty / k}, 0}, {Pos{tx / k, ty / k}, 0}, {Pos{tx / k, ty / k}, 0}, {Pos{tx / k, ty / k}, 0}}}
                : array<pair<Pos, uli>, 4>{{{Pos{tx / k - 1, ty / k}, tx % k + 1}, {Pos{tx / k, ty / k - 1}, ty % k + 1}, {Pos{tx / k + 1, ty / k}, k - tx % k}, {Pos{tx / k, ty / k + 1}, k - ty % k}}};
    uli ans = abs_minus(sx, tx) + abs_minus(sy, ty);
    for (auto i : sp)
      for (auto j : tp)
        ans = min(ans, k == 2 ? abs_minus(i.first.x, j.first.x) +
                                    abs_minus(i.first.y, j.first.y) +
                                    abs_minus(abs_minus(i.first.x, j.first.x),
                                              abs_minus(i.first.y, j.first.y)) /
                                        2 +
                                    i.second + j.second
                              : max(abs_minus(i.first.x, j.first.x),
                                    abs_minus(i.first.y, j.first.y)) *
                                        2 +
                                    i.second + j.second);
    cout << ans;
  }
  return 0;
}