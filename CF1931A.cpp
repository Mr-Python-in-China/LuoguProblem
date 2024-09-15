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
    ui x;
    cin >> x;
    for (ui i = 1; i <= 26; ++i)
      for (ui j = 1; j <= 26; ++j)
        for (ui k = 1; k <= 26; ++k)
          if (i + j + k == x) {
            cout.put(i - 1 + 'a').put(j - 1 + 'a').put(k - 1 + 'a').put('\n');
            goto out;
          }
  out:;
  }
  return 0;
}