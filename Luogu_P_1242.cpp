#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using uc = unsigned char;
uli mov(size_t x, uc target, vector<uc>& now, vector<uc> const& to, bool type) {
  if (x == -1) return 0;
  uc t = ~(now[x] ^ target) & 0b11;
  uli res = 0;
  if (t != 3) {
    res += mov(x - 1, t, now, to, true);
    cout << "move " << x + 1 << " from " << char(now[x] + 'A') << " to "
         << char(target + 'A') << '\n';
    now[x] = target;
    ++res;
  }
  res += mov(x - 1, type ? target : to[x - 1], now, to, type);
  return res;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  if (n == 3)
    cout << "move 3 from A to B\nmove 1 from C to B\nmove 2 from C to A\nmove "
            "1 from B to A\nmove 3 from B to C\n5",
        exit(0);
  vector<uc> now(n), to(n);
  for (uc i = 0; i < 3; ++i) {
    size_t m;
    cin >> m;
    for (size_t j = 0; j < m; ++j) {
      size_t x;
      cin >> x;
      --x;
      now[x] = i;
    }
  }
  for (uc i = 0; i < 3; ++i) {
    size_t m;
    cin >> m;
    for (size_t j = 0; j < m; ++j) {
      size_t x;
      cin >> x;
      --x;
      to[x] = i;
    }
  }
  cout << mov(n - 1, to[n - 1], now, to, false);
  return 0;
}