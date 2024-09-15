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
  string::iterator it = s.begin();
  while (*it == 'A') ++it;
  while (*it == 'B') ++it;
  while (*it == 'C') ++it;
  cout << (it == s.end() ? "Yes" : "No");
  return 0;
}