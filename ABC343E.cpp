#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
using si = short int;
struct point3d {
  signed char x, y, z;
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  usi r, s, t;
  cin >> r >> s >> t;
  point3d a, b, c;
  a.x = a.y = a.z = 0;
  for (b.x = -7; b.x <= 7; ++b.x)
    for (b.y = -7; b.y <= 7; ++b.y)
      for (b.z = -7; b.z <= 7; ++b.z)
        for (c.x = -7; c.x <= 7; ++c.x)
          for (c.y = -7; c.y <= 7; ++c.y)
            for (c.z = -7; c.z <= 7; ++c.z) {
              usi k = max<si>(min({a.x, b.x, c.x}) + 7 - max({a.x, b.x, c.x}),
                              0) *
                      max<si>(min({a.y, b.y, c.y}) + 7 - max({a.y, b.y, c.y}),
                              0) *
                      max<si>(min({a.z, b.z, c.z}) + 7 - max({a.z, b.z, c.z}),
                              0),
                  j = max<si>(min(b.x, c.x) + 7 - max(b.x, c.x), 0) *
                          max<si>(min(b.y, c.y) + 7 - max(b.y, c.y), 0) *
                          max<si>(min(b.z, c.z) + 7 - max(b.z, c.z), 0) +
                      max<si>(min<signed char>(0, b.x) + 7 -
                                  max<signed char>(0, b.x),
                              0) *
                          max<si>(min<signed char>(0, b.y) + 7 -
                                      max<signed char>(0, b.y),
                                  0) *
                          max<si>(min<signed char>(0, b.z) + 7 -
                                      max<signed char>(0, b.z),
                                  0) +
                      max<si>(min<signed char>(0, c.x) + 7 -
                                  max<signed char>(0, c.x),
                              0) *
                          max<si>(min<signed char>(0, c.y) + 7 -
                                      max<signed char>(0, c.y),
                                  0) *
                          max<si>(min<signed char>(0, c.z) + 7 -
                                      max<signed char>(0, c.z),
                                  0) -
                      3 * k,
                  i = 7 * 7 * 7 * 3 - 2 * j - 3 * k;
              if (i == r && j == s && k == t) {
                cout << "Yes\n"
                     << si(a.x) << ' ' << si(a.y) << ' ' << si(a.z) << ' '
                     << si(b.x) << ' ' << si(b.y) << ' ' << si(b.z) << ' '
                     << si(c.x) << ' ' << si(c.y) << ' ' << si(c.z);
                return 0;
              }
            }
  cout << "No";
  return 0;
}