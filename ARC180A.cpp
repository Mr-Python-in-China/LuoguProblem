#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<bool> a(n);
  for (vector<bool>::reference i : a) {
    char c;
    cin >> c;
    i = c == 'B';
  }
  size_t cnt = 0;
  bool l = !a.front();
  uli ans = 1;
  for (bool i : a)
    if (l == i)
      (ans *= (cnt + 1) / 2) %= uli(1e9 + 7), cnt = 1;
    else
      ++cnt, l = !l;
  (ans *= (cnt + 1) / 2) %= uli(1e9 + 7);
  cout << ans << '\n';
  return 0;
}