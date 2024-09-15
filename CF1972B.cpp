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
    cin >> n;
    vector<bool> a(n);
    for (vector<bool>::reference i : a) {
      char c;
      cin >> c;
      i = c == 'U';
    }
    bool flag = false;
    while (true) {
      vector<bool>::iterator it = find(a.begin(), a.end(), true);
      if (it == a.end()) break;
      vector<bool>::iterator pv = prev(it == a.begin() ? a.end() : it),
                             nt = next(it) == a.end() ? a.begin() : next(it);
      *pv = !*pv, *nt = !*nt;
      a.erase(it);
      flag = !flag;
    }
    cout << (flag ? "YES" : "NO") << '\n';
  }
  return 0;
}