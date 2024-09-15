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
    map<ui, pair<size_t, size_t>> cnt;
    vector<ui> a(n);
    for (ui& i : a) cin >> i;
    size_t ans1 = 0, ans2 = 0;
    {
      vector<ui>::iterator it = a.begin(), jt = a.end();
      while (it != a.end() && *it == a.front()) ++it;
      while (jt != it && *prev(jt) == a.front()) --jt;
      ans1 = jt - it;
    }
    {
      reverse(a.begin(), a.end());
      vector<ui>::iterator it = a.begin(), jt = a.end();
      while (it != a.end() && *it == a.front()) ++it;
      while (jt != it && *prev(jt) == a.front()) --jt;
      ans2 = jt - it;
    }
    cout << min(ans1, ans2) << '\n';
  }
  return 0;
}