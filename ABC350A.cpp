#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string s;
  cin >> s;
  cout << ((s[3] - '0') * 100 + (s[4] - '0') * 10 + (s[5] - '0') >= 1 &&
                   (s[3] - '0') * 100 + (s[4] - '0') * 10 + (s[5] - '0') <=
                       349 &&
                   s != "ABC316"
               ? "Yes"
               : "No");
  return 0;
}