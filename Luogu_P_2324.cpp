#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    uli d = 0;
    for (unsigned char i = 0; i < 25; ++i) {
      char c;
      cin >> c;
      d = (d << 2) | (c == '*'   ? 0b00
                      : c == '0' ? 0b01
                      : c == '1' ? 0b10
                                 : throw);
    }
    set<uli> vis{{d}};
    queue<uli> q{{d}};
    constexpr uli t = 0b0101010101'1001010101'1010000101'1010101001'1010101010;
    size_t cnt = 0;
    auto const f = [&vis, &q](uli p, unsigned char blank,
                              unsigned char target) {
      if ((p >> (target * 2) & 0b11) == 0b00) return false;
      p ^= (p >> (target * 2) & 0b11) << (blank * 2);
      p ^= (p >> (blank * 2) & 0b11) << (target * 2);
      p ^= (p >> (target * 2) & 0b11) << (blank * 2);
      if (!vis.count(p)) return vis.insert(p), q.push(p), true;
      return false;
    };
    while (++cnt <= 15 && !q.empty())
      for (size_t ss = q.size(); ss; --ss) {
        uli p = q.front();
        q.pop();
        if (p == t) goto end;
        for (unsigned char i = 0; i < 25; ++i)
          if ((p >> (i * 2) & 0b11) == 0) {
            if (i % 5 >= 2) {
              if (i >= 5) f(p, i, i - 7);
              if (i < 20) f(p, i, i + 3);
            }
            if (i % 5 < 3) {
              if (i >= 5) f(p, i, i - 3);
              if (i < 20) f(p, i, i + 7);
            }
            if (i % 5 >= 1) {
              if (i >= 10) f(p, i, i - 11);
              if (i < 15) f(p, i, i + 9);
            }
            if (i % 5 < 4) {
              if (i >= 10) f(p, i, i - 9);
              if (i < 15) f(p, i, i + 11);
            }
          }
      }
  end:;
    (cnt <= 15 ? cout << cnt : cout << "-1") << '\n';
  }
  return 0;
}