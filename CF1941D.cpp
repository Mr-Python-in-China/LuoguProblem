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
    size_t n, m, x;
    cin >> n >> m >> x;
    set<size_t> q({--x});
    while (m--) {
      size_t r;
      char op;
      cin >> r >> op;
      set<size_t> t;
      t.swap(q);
      for (size_t i : t) {
        if (op == '0') q.insert((i + r) % n);
        if (op == '1') q.insert((i + n - r) % n);
        if (op == '?') q.insert((i + r) % n), q.insert((i + n - r) % n);
      }
    }
    cout << q.size() << '\n';
    for (size_t i : q) cout << i + 1 << ' ';
    cout.put('\n');
  }
  return 0;
}