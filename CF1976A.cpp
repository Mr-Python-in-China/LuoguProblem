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
    size_t n;
    cin >> n;
    char lastdigit = '0', lastalpha = 'a';
    char flag = 0;
    while (n--) {
      char c;
      cin >> c;
      if (flag == -1) continue;
      if (isdigit(c)) {
        if (flag == 1) {
          flag = -1;
          continue;
        }
        if (c < lastdigit) {
          flag = -1;
          continue;
        }
        lastdigit = c;
      } else if (isalpha(c)) {
        flag = 1;
        if (c < lastalpha) {
          flag = -1;
          continue;
        }
        lastalpha = c;
      } else
        throw;
    }
    cout << (flag == -1 ? "NO\n" : "YES\n");
  }
  return 0;
}