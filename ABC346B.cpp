#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  unsigned short int w, b;
  cin >> w >> b;
  string s = "wbwbwwbwbwbw";
  for (unsigned char i = 0; i < 8; ++i) s = s + s;
  for (string::const_iterator it = s.cbegin(), jt = prev(it + w + b);
       jt < s.cend(); ++it, ++jt)
    if (count(it, next(jt), 'w') == w && count(it, next(jt), 'b') == b) {
      cout << "Yes";
      return 0;
    }
  cout << "No";
  return 0;
}