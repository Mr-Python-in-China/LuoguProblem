#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    if (s.front() != '1') {
      cout << "NO\n";
      continue;
    }
    bool b = 0;
    for (size_t i = s.size() - 1; i > 0; --i) {
      unsigned char d = s[i] - '0' - b;
      b = true;
      if (5 <= (d + 10) / 2 && (d + 10 + 1) / 2 <= 9)
        ;
      else {
        cout << "NO\n";
        goto failed;
      }
    }
    cout << "YES\n";
  failed:;
  }
  return 0;
}