#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
uli constexpr P = 1e8;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  sort(a.begin(), a.end());
  uli ans = 0, s = 0;
  for (vector<ui>::iterator it = a.begin(); it < a.end(); ++it) {
    vector<ui>::iterator jt = lower_bound(a.begin(), it, P - *it);
    // cerr<<*it<<' '<<s<<' '<<it-jt<<endl;
    ans += s + *it * uli(it - a.begin()) - P * (it - jt);
    s += *it;
  }
  cout << ans;
  return 0;
}