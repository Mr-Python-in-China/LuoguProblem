#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui d = 0;
  for (unsigned char i = 0; i < 16; ++i) {
    char c;
    cin >> c;
    d = (d << 2) + (c == 'O'   ? 0b00
                    : c == 'W' ? 0b10
                    : c == 'B' ? 0b01
                               : throw);
  }
  constexpr array<ui, 20> masks = {
      {
       0b01010101'00000000'00000000'00000000, 0b00000000'01010101'00000000'00000000,
       0b00000000'00000000'01010101'00000000, 0b00000000'00000000'00000000'01010101,
       0b01000000'01000000'01000000'01000000, 0b00010000'00010000'00010000'00010000,
       0b00000100'00000100'00000100'00000100, 0b00000001'00000001'00000001'00000001,
       0b01000000'00010000'00000100'00000001, 0b00000001'00000100'00010000'01000000,
       0b10101010'00000000'00000000'00000000, 0b00000000'10101010'00000000'00000000,
       0b00000000'00000000'10101010'00000000, 0b00000000'00000000'00000000'10101010,
       0b10000000'10000000'10000000'10000000, 0b00100000'00100000'00100000'00100000,
       0b00001000'00001000'00001000'00001000, 0b00000010'00000010'00000010'00000010,
       0b10000000'00100000'00001000'00000010, 0b00000010'00001000'00100000'10000000,
       }
  };
  size_t cnt1 = -1, cnt2 = -1;
  {
    set<ui> vis{{d}};
    queue<ui> q{{d}};
    unsigned char flag = 0b10;
    auto const f = [&vis, &q, &flag](ui p, unsigned char blank,
                                     unsigned char target) {
      if ((p >> (target * 2) & 0b11) != flag) return false;
      p ^= (p >> (target * 2) & 0b11) << (blank * 2);
      p ^= (p >> (blank * 2) & 0b11) << (target * 2);
      p ^= (p >> (target * 2) & 0b11) << (blank * 2);
      if (!vis.count(p)) return vis.insert(p), q.push(p), true;
      return false;
    };
    while (flag = (~flag) & 0b11, ++cnt1, !q.empty())
      for (size_t ss = q.size(); ss; --ss) {
        ui p = q.front();
        q.pop();
        for (auto i : masks)
          if ((p & i) == i) goto over1;
        for (unsigned char i = 0; i < 16; ++i)
          if ((p >> (i * 2) & 0b11) == 0) {
            if (i % 4 != 0) f(p, i, i - 1);
            if (i % 4 != 3) f(p, i, i + 1);
            if (i >= 4) f(p, i, i - 4);
            if (i < 12) f(p, i, i + 4);
          }
      }
  over1:;
  }
  {
    set<ui> vis{{d}};
    queue<ui> q{{d}};
    unsigned char flag = 0b01;
    auto const f = [&vis, &q, &flag](ui p, unsigned char blank,
                                     unsigned char target) {
      if ((p >> (target * 2) & 0b11) != flag) return false;
      p ^= (p >> (target * 2) & 0b11) << (blank * 2);
      p ^= (p >> (blank * 2) & 0b11) << (target * 2);
      p ^= (p >> (target * 2) & 0b11) << (blank * 2);
      if (!vis.count(p)) return vis.insert(p), q.push(p), true;
      return false;
    };
    while (flag = (~flag) & 0b11, ++cnt2, !q.empty())
      for (size_t ss = q.size(); ss; --ss) {
        ui p = q.front();
        q.pop();
        for (auto i : masks)
          if ((p & i) == i) goto over2;
        for (unsigned char i = 0; i < 16; ++i)
          if ((p >> (i * 2) & 0b11) == 0) {
            if (i % 4 != 0 && i >= 1) f(p, i, i - 1);
            if (i % 4 != 3 && i < 15) f(p, i, i + 1);
            if (i >= 4) f(p, i, i - 4);
            if (i < 12) f(p, i, i + 4);
          }
      }
  over2:;
  }
  cout << min(cnt1, cnt2);
  return 0;
}