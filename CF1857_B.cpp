#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    string::iterator seted = s.begin();
    for (string::iterator it = s.begin(); it < s.end(); it++)
      if (*it >= '5') {
        seted = next(it);
        string::iterator tmp = it;
        *it = '9' + 1;
        while (*tmp > '9') {
          *tmp = '0';
          if (++tmp == s.end()) {
            cout.put('1');
            break;
          }
          ++*tmp;
        }
      }
    for (size_t i = 0; i < s.size() - (seted - s.begin()); i++)
      cout.put(s[s.size() - 1 - i]);
    for (size_t i = (seted - s.begin()); i > 0; i--) cout.put('0');
    cout << '\n';
  }
  return 0;
}