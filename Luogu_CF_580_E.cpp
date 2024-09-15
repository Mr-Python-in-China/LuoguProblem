#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, k;
  cin >> n >> m >> k;
  string s;
  cin >> s;
  for (size_t i = 0; i < m + k; ++i) {
    char op;
    size_t l, r;
    cin >> op >> l >> r;
    --l;
    if (op == '1') {
      char c;
      cin >> c;
      fill(s.begin() + l, s.begin() + r, c);
    } else {
      size_t d;
      cin >> d;
      cout << (equal(s.begin() + l, s.begin() + r - d, s.begin() + l + d)
                   ? "YES\n"
                   : "NO\n");
    }
  }
  return 0;
}