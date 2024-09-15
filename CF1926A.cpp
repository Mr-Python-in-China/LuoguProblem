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
    unsigned char cA = 0, cB = 0;
    for (unsigned char i = 0; i < 5; ++i) {
      char c;
      cin >> c;
      c == 'A' ? ++cA : c == 'B' ? ++cB : throw;
    }
    cout.put(cA > cB ? 'A' : 'B').put('\n');
  }
  return 0;
}