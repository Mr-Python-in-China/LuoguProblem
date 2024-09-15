#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
ui inv(ui x) { return (~x) & 2147483647; }
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    multiset<ui> s;
    size_t su = 0;
    for (size_t i = 0; i < n; ++i) {
      ui x;
      cin >> x;
      multiset<ui>::iterator p = s.find(inv(x));
      if (p != s.end())
        s.erase(p), ++su;
      else
        s.insert(x);
    }
    cout << s.size() + su << '\n';
  }
  return 0;
}