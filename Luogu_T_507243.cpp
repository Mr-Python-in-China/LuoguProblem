#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  fin >> n;
  vector<ui> a(n);
  for (ui& i : a) fin >> i;
  auto jmpP = [&n](size_t p) { return p + 1 == n ? 0 : p + 1; };
  size_t maxp = max_element(a.begin(), a.end()) - a.begin();
  stack<size_t> stk({maxp});
  uli ans = 0;
  size_t prevp = maxp, p = jmpP(prevp);
  do {
    if (a[prevp] < a[p]) {
      while (!stk.empty() && a[stk.top()] <= a[p]) stk.pop();
      ans += a[p] - a[prevp];
    }
    stk.push(p);
    prevp = jmpP(prevp), p = jmpP(p);
  } while (prevp != maxp);
  fout << ans;
  return 0;
}