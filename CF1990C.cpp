#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
vector<ui> f(vector<ui> &a) {
  set<ui> s;
  vector<ui> res;
  ui maxx = 0;
  for (ui i : a) {
    if (s.count(i) && i > maxx) maxx = i;
    s.insert(i);
    res.push_back(maxx);
  }
  return res;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<ui> a(n);
    for (ui &i : a) cin >> i;
    vector<ui> b = f(a), c = f(b);
    uli sum = accumulate(a.begin(), a.end(), uli(0)) +
              accumulate(b.begin(), b.end(), uli(0));
    uli d = accumulate(c.begin(), c.end(), uli(0));
    while (!c.empty()) {
      sum += d;
      d -= c.back();
      c.pop_back();
    }
    cout << sum << '\n';
  }
  return 0;
}