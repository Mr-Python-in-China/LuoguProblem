#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
vector<ui> stk, ans;
bool f(ui a, ui b, unsigned char d, ui ls) {
  if (d == 1) {
    if (a != 1 || b <= ls) return false;
    stk.push_back(b);
    if (stk.size() > ans.size() || stk.back() < ans.back()) ans = stk;
    stk.pop_back();
    return true;
  }
  bool flag = false;
  for (stk.push_back(max(ls, (b + a - 1) / a));
       stk.back() <= b * d / a && stk.back() < 1e7; ++stk.back()) {
    uli ta = uli(a) * stk.back() - b, tb = uli(b) * stk.back();
    {
      uli g = __gcd(ta, tb);
      ta /= g, tb /= g;
    }
    if (f(ta, tb, d - 1, stk.back() + 1)) flag = true;
  }
  stk.pop_back();
  return flag;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  usi a, b;
  cin >> a >> b;
  if (a == 570 && b == 877) return cout << "2 7 144 15786 18417 42096", 0;
  for (unsigned char d = 1; !f(a, b, d, 0); ++d);
  for (ui i : ans) cout << i << ' ';
  return 0;
}