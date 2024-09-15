#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
usi constexpr match[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
usi get_match_count(usi x) {
  static array<ui, 19999> mem({});
  if (mem[x]) return mem[x];
  usi ans = 0, t = x;
  do ans += match[t % 10], t /= 10;
  while (t);
  return mem[x] = ans;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  usi n;
  cin >> n;
  n -= 4;
  ui ans = 0;
  for (usi a = 0; a < 10000; ++a)
    for (usi b = 0; b < 10000; ++b) {
      usi c = a + b;
      if (get_match_count(a) + get_match_count(b) + get_match_count(c) == n)
        ++ans;
    }
  cout << ans;
  return 0;
}