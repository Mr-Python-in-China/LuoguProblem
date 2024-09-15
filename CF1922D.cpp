#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct act {
  ui a, d;
  bool flag;
  act(void): flag(false) {}
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    list<act> s(n);
    for (act& i : s) cin >> i.a;
    for (act& i : s) cin >> i.d;
    vector<list<act>::iterator> q(n);
    iota(q.begin(), q.end(), s.begin());
    for (size_t i = 0; i < n; ++i) {
      vector<list<act>::iterator> r;
      for (list<act>::iterator it : q)
        if ((it == s.begin() ? 0 : prev(it)->a) +
                (next(it) == s.end() ? 0 : next(it)->a) >=
            it->d) {
          it->flag = true;
          if (it != s.begin()) r.push_back(prev(it));
          if (next(it) != s.end()) r.push_back(next(it));
        }
      size_t ans = 0;
      for (list<act>::iterator it : q)
        if (it->flag) s.erase(it), ++ans;
      q.swap(r);
      cout << ans << ' ';
    }
    cout << '\n';
  }
  return 0;
}