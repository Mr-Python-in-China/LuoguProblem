#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  string s;
  cin >> s >> n;
  string rgs;
  for (char i : s) {
    if (i == '*')
      rgs += ".*";
    else if (i == '?')
      rgs += '.';
    else
      rgs += i;
  }
  regex rg(rgs = '^' + rgs + '$');
  while (n--) {
    string t;
    cin >> t;
    cout << (regex_match(t, rg) ? "YES" : "NO") << '\n';
  }
  return 0;
}