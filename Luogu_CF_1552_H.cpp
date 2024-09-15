#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using uc = unsigned char;
using usi = unsigned short int;
struct pos {
  uc x, y;
  pos(uc _x, uc _y): x(_x), y(_y) {}
};
usi ask(vector<pos> const& p) {
  cout << "? " << p.size() << '\n';
  for (pos i : p) cout << i.x + 1 << ' ' << i.y + 1 << '\n';
  flush(cout);
  usi res;
  cin >> res;
  return res;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  usi s = ask([]() {
    vector<pos> res;
    for (uc i = 0; i < 200; ++i)
      for (uc j = 0; j < 200; ++j) res.emplace_back(i, j);
    return res;
  }());
  uc l = 1, r = 8;
  usi t;
  while (l < r) {
    uc mid = (l + r) / 2;
    usi q = ask([mid]() {
      vector<pos> res;
      for (usi i = 0; i < 200; i += 1 << mid)
        for (uc j = 0; j < 200; ++j) res.emplace_back(i, j);
      return res;
    }());
    q * (1 << mid) == s ? l = mid + 1 : (t = q, r = mid);
  }
  if (l == 8) t = s / 128;
  uc a =
      (max<usi>(t * (1 << l), s) - min<usi>(t * (1 << l), s)) / (1 << l >> 1);
  cerr << (t) << ' ' << (s) << ' ' << ui(l) << ' ' << ui(a) << endl;
  cout << "! " << (a - 1 + s / a - 1) * 2;
  return 0;
}