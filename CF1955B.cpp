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
    size_t n;
    ui c, d;
    cin >> n >> c >> d;
    multiset<ui> r;
    for (size_t i = 0; i < n * n; ++i) {
      ui x;
      cin >> x;
      r.insert(x);
    }
    ui s = *r.begin();
    for (size_t i = 0; i < n; ++i) {
      multiset<ui>::iterator it = r.find(s);
      if (it == r.end()) {
        cout << "NO\n";
        goto failed;
      }
      ui t = *it;
      r.erase(it);
      s += d;
      for (size_t j = 1; j < n; ++j) {
        multiset<ui>::iterator jt = r.find(t += c);
        if (jt == r.end()) {
          cout << "NO\n";
          goto failed;
        }
        r.erase(jt);
      }
    }
    cout << "YES\n";
  failed:;
  }
  return 0;
}