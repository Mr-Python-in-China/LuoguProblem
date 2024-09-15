#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli n;
  cin >> n;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  n -= 2;
  uli d = 1, w = 18;
  while (n >= w) n -= w, d *= 10, w *= 10;
  if (n >= w / 2) {
    string str = to_string(n - w / 2 + d);
    cout << str + string(str.rbegin(), str.rend());
  } else {
    string str = to_string(n + d);
    cout << str + string(next(str.rbegin()), str.rend());
  }
  return 0;
}